#ifndef SCHEDULER_H
#define SCHEDULER_H

/** The procedure of a task is a void(void) function */
typedef void(*task_proc)(void);

enum crontab_arguments {
  CRON_MINUTE = 0,
  CRON_HOUR,
  CRON_MONTH_DAY,
  CRON_MONTH,
  CRON_WEEK_DAY,
  CRON_ARGC,
};

typedef struct task * task_t;
typedef short crontab_rule_t[CRON_ARGC];

/**
* Builds a task that executes procedure when crontab_values indicates.
* @method scheduler_build_task
* @param  procedure                  The procedure of the task
* @param  rule                       The crontab rule splitted in its values,
*                                    -1 means wildcard (*).
*/
task_t
scheduler_build_task(task_proc procedure, crontab_rule_t rule);

/**
 * Adds a task to the task scheduler
 * @method scheduler_add_task
 * @param  task                   The task to add
 */
void
scheduler_add_task(task_t task);

/**
 * Schedules the added tasks (runs infinitely)
 * @method scheduler_schedule_tasks
 */
void
scheduler_schedule_tasks();

#endif
