#ifndef AST_NODE_TYPES_H
#define AST_NODE_TYPES_H

#include <unistd.h>
#include <scheduler.h>

typedef struct ast_program * ast_program_t;
typedef struct ast_globals * ast_globals_t;
typedef struct ast_global * ast_global_t;
typedef struct ast_tasks * ast_tasks_t;
typedef struct ast_task * ast_task_t;
typedef struct ast_variables * ast_variables_t;
typedef struct ast_variable * ast_variable_t;
typedef struct ast_code * ast_code_t;
typedef struct ast_assignment * ast_assignment_t;
typedef struct ast_arithmetic * ast_arithmetic_t;
typedef struct ast_if_block * ast_if_block_t;
typedef struct ast_while_block * ast_while_block_t;
typedef struct ast_boolean * ast_boolean_t;
typedef struct ast_scheduler * ast_scheduler_t;
typedef struct ast_scheduled_task * ast_scheduled_task_t;
typedef union ast_code_child * ast_code_child_t;

enum ast_code_child_type {
  CODE_ASSIGNMENT,
  CODE_IF,
  CODE_WHILE,
};
typedef enum ast_code_child_type ast_code_child_type_t;
enum ast_arithmetic_type {
  AST_ARIT_SUM,
  AST_ARIT_DIF,
  AST_ARIT_PROD,
  AST_ARIT_DIV,
  AST_ARIT_CONST,
  AST_ARIT_VARIABLE,
};
typedef enum ast_arithmetic_type ast_arithmetic_type_t;
enum ast_boolean_type {
  AST_BOOL_AND,
  AST_BOOL_OR,
  AST_BOOL_NOT,
  AST_BOOL_TRUE,
  AST_BOOL_FALSE,
};
typedef enum ast_boolean_type ast_boolean_type_t;

struct ast_program {
  ast_globals_t globals;
  ast_tasks_t tasks;
  ast_scheduler_t scheduler;
};
struct ast_globals {
  size_t size;
  ast_global_t * globals;
};
struct ast_global {
  char * name;
};
struct ast_tasks {
  size_t size;
  ast_task_t * tasks;
};
struct ast_task {
  char * name;
  ast_variables_t variables;
  ast_code_t code;
};
struct ast_variables {
  size_t size;
  ast_variable_t * variables;
};
struct ast_variable {
  char * name;
};
struct ast_code {
  size_t size;
  ast_code_child_t * childs;
};
struct ast_assignment {
  ast_code_child_type_t code_child_type;
  char * var_name;
  ast_arithmetic_t arithmetic;
};
struct ast_base_code_child {
  ast_code_child_type_t code_child_type;
};
struct ast_arithmetic {
  ast_arithmetic_type_t type;
  ast_arithmetic_t op1;
  ast_arithmetic_t op2;
  char * var_id;
  int value;
};
struct ast_if_block {
  ast_boolean_t boolean;
  ast_code_child_type_t code_child_type;
  ast_code_t code;
};
struct ast_while_block {
  ast_boolean_t boolean;
  ast_code_child_type_t code_child_type;
  ast_code_t code;
};
struct ast_boolean {
  ast_boolean_type_t type;
  ast_boolean_t op1;
  ast_boolean_t op2;
};
struct ast_scheduler {
  size_t size;
  ast_scheduled_task_t * scheduled_tasks;
};
struct ast_scheduled_task {
  char * task_name;
  crontab_rule_t rule;
};

union ast_code_child {
  struct ast_assignment assignment;
  struct ast_if_block if_block;
  struct ast_while_block while_block;
  struct ast_base_code_child base;
};

#endif
