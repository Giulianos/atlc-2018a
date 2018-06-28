#include "ast_node_print.h"
#include <stdio.h>

FILE * output_file;

void
ast_program_print(ast_program_t program)
{
  fprintf(output_file,
          "#include \"scheduler.h\"\n"
          "#include <stdio.h>\n"
          "#include <stdbool.h>\n");
  ast_globals_print(program->globals);
  ast_tasks_print(program->tasks);
  ast_scheduler_print(program->scheduler);
}

void
ast_globals_print(ast_globals_t globals)
{
  int i = 0;

  for(; i < globals->size; i++) {
    ast_global_print(globals->globals[i]);
  }
}

void
ast_global_print(ast_global_t global)
{
  /** TODO: get the global type from symbol table */
  fprintf(output_file, "int %s;\n", global->name);
}

void
ast_tasks_print(ast_tasks_t tasks)
{
  int i = 0;

  for(; i < tasks->size; i++) {
    ast_task_print(tasks->tasks[i]);
  }
}

void
ast_task_print (ast_task_t task)
{
  fprintf(output_file, "void %s(){\n", task->name);
  ast_code_print(task->code);
  fprintf(output_file, "}\n");
}

void
ast_variables_print(ast_variables_t variables)
{
  int i = 0;

  for(; i < variables->size; i++) {
    ast_variable_print(variables->variables[i]);
  }
}

void
ast_variable_print(ast_variable_t variable)
{
  /** TODO: get the variable type from symbol table */
  fprintf(output_file, "int %s;\n", variable->name);
}

void
ast_code_print(ast_code_t code)
{
  int i = 0;

  for(; i < code->size; i++) {
    switch (code->childs[i]->base.code_child_type) {
      case CODE_ASSIGNMENT:
        fprintf(output_file, "%s=", code->childs[i]->assignment.var_name);
        ast_arithmetic_print(code->childs[i]->assignment.arithmetic);
        fprintf(output_file, ";");
        break;
      case CODE_IF:
        fprintf(output_file, "if(");
        ast_boolean_print(code->childs[i]->if_block.boolean);
        fprintf(output_file, "){");
        ast_code_print(code->childs[i]->if_block.code);
        fprintf(output_file, "}");
        break;
      case CODE_WHILE:
      fprintf(output_file, "while(");
      ast_boolean_print(code->childs[i]->while_block.boolean);
      fprintf(output_file, "){");
      ast_code_print(code->childs[i]->while_block.code);
      fprintf(output_file, "}");
        break;
    }
  }
}

void
ast_arithmetic_print(ast_arithmetic_t arithmetic)
{
  switch(arithmetic->type) {
    case AST_ARIT_SUM:
      fprintf(output_file, "(");
      ast_arithmetic_print(arithmetic->op1);
      fprintf(output_file, " + ");
      ast_arithmetic_print(arithmetic->op2);
      fprintf(output_file, ")");
      break;
    case AST_ARIT_DIF:
      fprintf(output_file, "(");
      ast_arithmetic_print(arithmetic->op1);
      fprintf(output_file, " + ");
      ast_arithmetic_print(arithmetic->op2);
      fprintf(output_file, ")");
      break;
    case AST_ARIT_PROD:
      fprintf(output_file, "(");
      ast_arithmetic_print(arithmetic->op1);
      fprintf(output_file, " * ");
      ast_arithmetic_print(arithmetic->op2);
      fprintf(output_file, ")");
      break;
    case AST_ARIT_DIV:
      fprintf(output_file, "(");
      ast_arithmetic_print(arithmetic->op1);
      fprintf(output_file, " - ");
      ast_arithmetic_print(arithmetic->op2);
      fprintf(output_file, ")");
      break;
    case AST_ARIT_CONST:
      fprintf(output_file, "%d", arithmetic->value);
      break;
    case AST_ARIT_VARIABLE:
      fprintf(output_file, "%s", arithmetic->var_id);
      break;
  }
}

void
ast_boolean_print(ast_boolean_t boolean)
{
  switch(boolean->type) {
    case AST_BOOL_AND:
      fprintf(output_file, "(");
      ast_boolean_print(boolean->op1);
      fprintf(output_file, " && ");
      ast_boolean_print(boolean->op2);
      fprintf(output_file, ")");
      break;
    case AST_BOOL_OR:
      fprintf(output_file, "(");
      ast_boolean_print(boolean->op1);
      fprintf(output_file, " || ");
      ast_boolean_print(boolean->op2);
      fprintf(output_file, ")");
      break;
    case AST_BOOL_NOT:
      fprintf(output_file, "!(");
      ast_boolean_print(boolean->op1);
      fprintf(output_file, ")");
      break;
    case AST_BOOL_TRUE:
      fprintf(output_file,"true\n");
      break;
    case AST_BOOL_FALSE:
      fprintf(output_file,"false\n");
      break;
  }
}

void
ast_scheduler_print(ast_scheduler_t scheduler)
{
  int i = 0;

  fprintf(output_file, "int main(int argc, char * argv[]) {"
            "crontab_rule_t rule;"
            "task_t task;\n");
  for(; i < scheduler->size; i++) {
    ast_scheduled_task_print(scheduler->scheduled_tasks[i]);
  }
  fprintf(output_file, "scheduler_schedule_tasks(); }\n");
}

void
ast_scheduled_task_print (ast_scheduled_task_t scheduled_task)
{
  fprintf(output_file, "rule[CRON_MINUTE]    = %d;"
         "rule[CRON_HOUR]      = %d;"
         "rule[CRON_MONTH_DAY] = %d;"
         "rule[CRON_MONTH]     = %d;"
         "rule[CRON_WEEK_DAY]  = %d;\n",
          scheduled_task->rule[CRON_MINUTE],
          scheduled_task->rule[CRON_HOUR],
          scheduled_task->rule[CRON_MONTH_DAY],
          scheduled_task->rule[CRON_MONTH],
          scheduled_task->rule[CRON_WEEK_DAY]);
  fprintf(output_file, "task = scheduler_build_task(%s, rule);\n", scheduled_task->task_name);
  fprintf(output_file, "scheduler_add_task(task);\n");
}
