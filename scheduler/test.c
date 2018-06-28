#include "scheduler.h"
#include <stdio.h>

int global1;

void
print_hello_world()
{
  puts("Hello World!");
}

void
print_always()
{
  puts("This is called every minute!");
}

int
main(int argc, char * argv[]) {
  crontab_rule_t rule;
  task_t task;

  /**
   * Set rule to 11 21 * * *
   */
  rule[CRON_MINUTE]    = 11;
  rule[CRON_HOUR]      = 21;
  rule[CRON_MONTH_DAY] = -1;
  rule[CRON_MONTH]     = -1;
  rule[CRON_WEEK_DAY]  = -1;

  /** Build task */
  task = scheduler_build_task(print_hello_world, rule);

  /** Add task to scheduler */
  scheduler_add_task(task);

  /**
   * Set rule to 10 21 * * *
   */
  rule[CRON_MINUTE]    = 10;
  rule[CRON_HOUR]      = 21;
  rule[CRON_MONTH_DAY] = -1;
  rule[CRON_MONTH]     = -1;
  rule[CRON_WEEK_DAY]  = -1;

  /** Build task */
  task = scheduler_build_task(print_hello_world, rule);

  /** Add task to scheduler */
  scheduler_add_task(task);

  /**
   * Set rule to * * * * *
   */
  rule[CRON_MINUTE]    = -1;
  rule[CRON_HOUR]      = -1;
  rule[CRON_MONTH_DAY] = -1;
  rule[CRON_MONTH]     = -1;
  rule[CRON_WEEK_DAY]  = -1;

  /** Build task */
  task = scheduler_build_task(print_hello_world, rule);

  /** Add task to scheduler */
  scheduler_add_task(task);

  /** Schedule task */
  scheduler_schedule_tasks();

  return 0;
}
