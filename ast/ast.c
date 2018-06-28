#include "ast.h"
#include <stdlib.h>
#include <string.h>

ast_program_t ast_program_new(ast_globals_t globals, ast_tasks_t tasks, ast_scheduler_t scheduler)
{
  ast_program_t ret = malloc(sizeof(struct ast_program));
  ret->globals = globals;
  ret->tasks = tasks;
  ret->scheduler = scheduler;
  return ret;
}

ast_globals_t ast_globals_new(ast_global_t global)
{
  ast_globals_t ret = malloc(sizeof(struct ast_globals));
  ret->globals = malloc(sizeof(struct ast_global));
  ret->globals[0] = global;
  ret->size = 1;
  return ret;
}

ast_globals_t ast_globals_add(ast_globals_t globals, ast_global_t global)
{
  globals->size++;
  globals->globals = realloc(globals->globals, globals->size * sizeof(global));
  globals->globals[globals->size-1] = global;
  return globals;
}

ast_global_t ast_global(char * name)
{
  ast_global_t ret = malloc(sizeof(struct ast_global));
  ret->name = name;
  return ret;
}

ast_tasks_t ast_tasks_new(ast_task_t task)
{
  ast_tasks_t ret = malloc(sizeof(struct ast_tasks));
  ret->tasks = malloc(sizeof(struct ast_task));
  ret->tasks[0] = task;
  ret->size = 1;
  return ret;
}

ast_tasks_t ast_tasks_add(ast_tasks_t tasks, ast_task_t task)
{
  tasks->size++;
  tasks->tasks = realloc(tasks->tasks, tasks->size * sizeof(task));
  tasks->tasks[tasks->size-1] = task;
  return tasks;
}

ast_task_t ast_task_new (ast_code_t code)
{
  ast_task_t ret = malloc(sizeof(struct ast_task));
  ret->code = code;
  return ret;
}

ast_variables_t ast_variables_new(ast_variable_t variable)
{
  ast_variables_t ret = malloc(sizeof(struct ast_variables));
  ret->variables = malloc(sizeof(struct ast_variable));
  ret->variables[0] = variable;
  ret->size = 1;
  return ret;
}

ast_variables_t ast_variables_add(ast_variables_t variables, ast_variable_t variable)
{
  variables->size++;
  variables->variables = realloc(variables->variables, variables->size * sizeof(variable));
  variables->variables[variables->size-1] = variable;
  return variables;
}

ast_variable_t ast_variable_new(char * name)
{
  ast_variable_t ret = malloc(sizeof(struct ast_variable));
  ret->name = name;
  return ret;
}

ast_code_t ast_code_new(ast_code_child_t child)
{
  ast_code_t ret = malloc(sizeof(struct ast_code));
  ret->childs = malloc(sizeof(union ast_code_child));
  ret->childs[0] = child;
  ret->size = 1;
  return ret;
}

ast_code_t ast_code_add(ast_code_t code, ast_code_child_t code_child)
{
  code->size++;
  code->childs = realloc(code->childs, code->size * sizeof(code_child));
  code->childs[code->size-1] = code_child;
  return code;
}

ast_assignment_t ast_assignment_new(ast_code_child_type_t code_child_type, char * var_name, ast_arithmetic_t arithmetic)
{
  ast_assignment_t ret = malloc(sizeof(struct ast_assignment));
  ret->code_child_type = code_child_type;
  ret->var_name = var_name;
  ret->arithmetic = arithmetic;
  return ret;
}

ast_arithmetic_t ast_arithmetic_new(ast_arithmetic_type_t type, ast_arithmetic_t op1, ast_arithmetic_t op2)
{
  ast_arithmetic_t ret = malloc(sizeof(struct ast_arithmetic));
  ret->type = type;
  ret->op1 = op1;
  ret->op2 = op2;
  return ret;
}

ast_if_block_t ast_if_block_new(ast_code_child_type_t code_child_type, ast_code_t code)
{
  ast_if_block_t ret = malloc(sizeof(struct ast_if_block));
  ret->code_child_type = code_child_type;
  ret->code = code;
  return ret;
}

ast_while_block_t ast_while_block_new(ast_code_child_type_t code_child_type, ast_code_t code)
{
  ast_while_block_t ret = malloc(sizeof(struct ast_while_block));
  ret->code_child_type = code_child_type;
  ret->code = code;
  return ret;
}

ast_boolean_t ast_boolean_new(ast_boolean_type_t type, ast_boolean_t op1, ast_boolean_t op2)
{
  ast_boolean_t ret = malloc(sizeof(struct ast_boolean));
  ret->type = type;
  ret->op1 = op1;
  ret->op2 = op2;
  return ret;
}

ast_scheduler_t ast_scheduler_new(ast_scheduled_task_t scheduled_task)
{
  ast_scheduler_t ret = malloc(sizeof(struct ast_scheduler));
  ret->scheduled_tasks = malloc(sizeof(struct ast_scheduled_task));
  ret->scheduled_tasks[0] = scheduled_task;
  ret->size = 1;
  return ret;
}

ast_scheduler_t ast_scheduler_add(ast_scheduler_t scheduler, ast_scheduled_task_t scheduled_task)
{
scheduler->size++;
scheduler->scheduled_tasks = realloc(scheduler->scheduled_tasks, scheduler->size * sizeof(scheduled_task));
scheduler->scheduled_tasks[scheduler->size-1] = scheduled_task;
return scheduler;
}

ast_scheduled_task_t ast_scheduled_task_new (char * task_name, crontab_rule_t rule)
{
  ast_scheduled_task_t ret = malloc(sizeof(struct ast_scheduled_task));
  ret->task_name = task_name;
  memcpy(ret->rule, rule, sizeof(crontab_rule_t));
  return ret;
}
