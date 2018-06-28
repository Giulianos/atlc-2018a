#include <scheduler.h>
#include <scheduler_private.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/** Task object definition */
struct task {
  task_proc procedure;
  crontab_rule_t rule;
  task_t next_task;
};

typedef struct task ctask_t;

task_t first_task = NULL;
task_t last_task = NULL;

task_t
scheduler_build_task(task_proc procedure, crontab_rule_t rule)
{
  if(scheduler_valid_crontab_rule(rule)) {
    task_t new_task = malloc(sizeof(ctask_t));
    if(new_task == NULL) {
      return NULL;
    }

    new_task->procedure = procedure;
    new_task->rule[CRON_MINUTE]    = rule[CRON_MINUTE];
    new_task->rule[CRON_MINUTE]    = rule[CRON_MINUTE];
    new_task->rule[CRON_HOUR]      = rule[CRON_HOUR];
    new_task->rule[CRON_MONTH_DAY] = rule[CRON_MONTH_DAY];
    new_task->rule[CRON_MONTH]     = rule[CRON_MONTH];
    new_task->rule[CRON_WEEK_DAY]  = rule[CRON_WEEK_DAY];
    new_task->next_task = NULL;

    return new_task;
  }
  return NULL;
}

void
scheduler_add_task(task_t task)
{
  /** The list of tasks is empty */
  if(first_task == NULL && last_task == NULL) {
    last_task = first_task = task;
    return;
  }

  /** Insert at the end of the list */
  last_task->next_task = task;
  last_task = task;
}

void
scheduler_schedule_tasks()
{
  time_t current_time;
  struct tm current_time_broken_out;
  bool round_time = true;

  while(true) {
    /** Get current time */
    current_time = time(NULL);
    localtime_r(&current_time, &current_time_broken_out);

    /** Run corresponding tasks */
    scheduler_run_tasks(&current_time_broken_out);

    if(round_time) {
      /** Sleep till next rounded time */
      sleep(60 - current_time_broken_out.tm_sec);
      round_time = false;
    } else {
      /** Sleep till next minute (60s - time taken to process tasks) */
      sleep(60 - difftime(time(NULL), current_time));
    }
  }
}

static void
scheduler_run_tasks(const struct tm * now)
{
  task_t current_task = first_task;
  pthread_t task_thread;

  if(current_task == NULL) {
    return;
  }

  while(current_task != NULL) {
    if(scheduler_should_run_task(now, current_task)) {
      /** Create thread and run task */
      pthread_create(&task_thread, NULL,
                     scheduler_task_procedure_wrapper,
                     (void *)(current_task->procedure)
                    );
      /** Detach thread, we won't be joining */
      pthread_detach(task_thread);
    }
    current_task = current_task->next_task;
  }
}

static void *
scheduler_task_procedure_wrapper(void * data) {
  task_proc procedure = (task_proc)data;

  procedure();
  return 0;
}

static bool
scheduler_should_run_task(const struct tm * now, const task_t task)
{
  if(task->rule[CRON_MINUTE] != -1 &&
     task->rule[CRON_MINUTE] != now->tm_min) {
       return false;
  }

  if(task->rule[CRON_HOUR] != -1 &&
     task->rule[CRON_HOUR] != now->tm_hour) {
       return false;
  }

  if(task->rule[CRON_MONTH_DAY] != -1 &&
     task->rule[CRON_MONTH_DAY] != now->tm_mday) {
       return false;
  }

  /** now->tm_mon = [0:11] but cron_month = [1:12] */
  if(task->rule[CRON_MONTH] != -1 &&
     task->rule[CRON_MONTH] != now->tm_mon + 1) {
       return false;
  }

  if(task->rule[CRON_WEEK_DAY] != -1 &&
     task->rule[CRON_WEEK_DAY] != now->tm_wday) {
       return false;
  }
  return true;
}

static bool
scheduler_valid_crontab_rule(crontab_rule_t rule)
{
  if(rule == NULL) {
    return false;
  }

  if(rule[CRON_MINUTE] > 59 ||
     rule[CRON_MINUTE] < -1) {
    return false;
  }

  if(rule[CRON_HOUR] > 23 ||
     rule[CRON_HOUR] < -1) {
    return false;
  }

  if(rule[CRON_MONTH_DAY] > 31 ||
     rule[CRON_MONTH_DAY] < -1 ||
     rule[CRON_MONTH_DAY] == 0) {
    return false;
  }

  if(rule[CRON_MONTH] > 12 ||
     rule[CRON_MONTH] < -1 ||
     rule[CRON_MONTH] == 0) {
    return false;
  }

  if(rule[CRON_WEEK_DAY] > 6 ||
     rule[CRON_WEEK_DAY] < -1) {
    return false;
  }

  return true;
}
