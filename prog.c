#include "scheduler.h"
#include <stdio.h>
#include <stdbool.h>
int var1;
void mitarea(){
}
int main(int argc, char * argv[]) {crontab_rule_t rule;task_t task;
rule[CRON_MINUTE]    = -1;rule[CRON_HOUR]      = -1;rule[CRON_MONTH_DAY] = -1;rule[CRON_MONTH]     = -1;rule[CRON_WEEK_DAY]  = -1;
task = scheduler_build_task(mi_tarea, rule);
scheduler_add_task(task);
scheduler_schedule_tasks(); }
