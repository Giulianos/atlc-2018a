#ifndef AST_H
#define AST_H

#include "ast_node_types.h"

/** ast node constructors */

ast_program_t ast_program_new(ast_globals_t globals, ast_tasks_t tasks, ast_scheduler_t scheduler);
ast_globals_t ast_globals_new(ast_global_t global);

ast_globals_t ast_globals_add(ast_globals_t globals, ast_global_t global);

ast_global_t ast_global(char * name);

ast_tasks_t ast_tasks_new(ast_task_t task);

ast_tasks_t ast_tasks_add(ast_tasks_t tasks, ast_task_t task);

ast_task_t ast_task_new (ast_code_t code);

ast_variables_t ast_variables_new(ast_variable_t variable);

ast_variables_t ast_variables_add(ast_variables_t variables, ast_variable_t variable);

ast_variable_t ast_variable_new(char * name);

ast_code_t ast_code_new(ast_code_child_t child);

ast_code_t ast_code_add(ast_code_t code, ast_code_child_t code_child);

ast_assignment_t ast_assignment_new(ast_code_child_type_t code_child_type, char * var_name, ast_arithmetic_t arithmetic);

ast_arithmetic_t ast_arithmetic_new(ast_arithmetic_type_t type, ast_arithmetic_t op1, ast_arithmetic_t op2);

ast_if_block_t ast_if_block_new(ast_code_child_type_t code_child_type, ast_code_t code);

ast_while_block_t ast_while_block_new(ast_code_child_type_t code_child_type, ast_code_t code);

ast_boolean_t ast_boolean_new(ast_boolean_type_t type, ast_boolean_t op1, ast_boolean_t op2);

ast_scheduler_t ast_scheduler_new(ast_scheduled_task_t scheduled_task);

ast_scheduler_t ast_scheduler_add(ast_scheduler_t scheduler, ast_scheduled_task_t scheduled_task);

ast_scheduled_task_t ast_scheduled_task_new (char * task_name, crontab_rule_t rule);


#endif
