#ifndef SCHEDULER_PRIVATE
#define SCHEDULER_PRIVATE

#include <sys/time.h>
#include <stdbool.h>
#include <time.h>

/**
 * Checks if a crontab rule is valid
 * @method scheduler_valid_crontab_rule
 * @param  rule                         The rule to check
 * @return                              true if valid, false otherwise.
 */
static bool scheduler_valid_crontab_rule(crontab_rule_t rule);

/**
 * Checks if a task should be executed based on current time
 * @method scheduler_should_run_task
 * @param  now                       Current time
 * @param  task                      Task to check
 * @return                           true if the task should be executed,
 *                                   false otherwise.
 */
static bool scheduler_should_run_task(const struct tm * now, const task_t task);

/**
 * Iterates through the list of tasks and runs the corresponding ones based
 * on current time.
 * @method scheduler_run_tasks
 * @param  now                 Current time
 */
static void scheduler_run_tasks(const struct tm * now);

/**
 * Wrapper function to run on new thread, just to avoid casts.
 * @method scheduler_task_procedure_wrapper
 * @param  data                             the data passed to the function
 *                                          while creating the thread, it must
 *                                          be the procedure to run.
 * @return                                  always returns 0.
 */
static void * scheduler_task_procedure_wrapper(void * data);


#endif
