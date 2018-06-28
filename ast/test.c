#include "ast.h"
#include "ast_node_print.h"
#include <stdio.h>

extern FILE * output_file;

int
main(int argc, char * argv[])
{
  output_file = stdout;

  crontab_rule_t my_rule = {1, 2, 3, 2, 1};

  ast_globals_t globals = ast_globals_new(ast_global_new("glob1"));

  ast_tasks_t tasks = ast_tasks_new(
    ast_task_new(
      "task1",
      ast_code_new(
        (ast_code_child_t) ast_assignment_new(
          "glob1",
          ast_arithmetic_new(
            AST_ARIT_CONST,
            NULL,
            NULL,
            NULL,
            12
          )
        )
      )
    )
  );

  ast_scheduler_t scheduler = ast_scheduler_new(
    ast_scheduled_task_new(
      "task1",
      my_rule
    )
  );

  ast_program_print(
    ast_program_new(globals, tasks, scheduler)
  );


}
