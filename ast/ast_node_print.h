#ifndef AST_NODE_PRINT_H
#define AST_NODE_PRINT_H

#include "ast.h"
#include <scheduler.h>

/** ast node printers */

void
ast_program_print(ast_program_t program);
void
ast_globals_print(ast_globals_t globals);
void
ast_global_print(ast_global_t global);
void
ast_tasks_print(ast_tasks_t tasks);
void
ast_task_print (ast_task_t task);
void
ast_variables_print(ast_variables_t variables);
void
ast_variable_print(ast_variable_t variable);
void
ast_code_print(ast_code_t code);
void
ast_code_child_print(ast_code_child_t code_child);
void
ast_assignment_print(ast_assignment_t assignment);
void
ast_arithmetic_print(ast_arithmetic_t arithmetic);
void
ast_if_block_print(ast_if_block_t if_block);
void
ast_while_block_print(ast_while_block_t while_block);
void
ast_boolean_print(ast_boolean_t boolean);
void
ast_scheduler_print(ast_scheduler_t scheduler);
void
ast_scheduled_task_print (ast_scheduled_task_t scheduled_task);

#endif
