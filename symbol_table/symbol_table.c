#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SYM_TABLE_PREALLOC  10

static symbol_t * variables_table = NULL;
static symbol_t * tasks_table = NULL;
static symbol_t * globals_table = NULL;

static size_t variables_table_size = 0;
static size_t tasks_table_size = 0;
static size_t globals_table_size = 0;

static bool
symbol_table_guarantee_space(symbol_type_t table);

void
symbol_table_add_symbol(symbol_t symbol)
{

  if(!symbol_table_guarantee_space(symbol->base.type)) {
    /** Error allocating space */
    exit(1);
  }

  switch(symbol->base.type) {
    case SYMBOL_VARIABLE:
      variables_table[variables_table_size] = symbol;
      variables_table_size++;
      break;
    case SYMBOL_TASK:
      tasks_table[tasks_table_size] = symbol;
      tasks_table_size++;
      break;
    case SYMBOL_GLOBAL:
      globals_table[globals_table_size] = symbol;
      globals_table_size++;
      break;
  }
}

symbol_t
symbol_table_create_variable(const char * identifier, variable_type_t type
                                                    , symbol_task_t scope)
{
  symbol_t ret = malloc(sizeof(union symbol));
  ret->variable.type = SYMBOL_VARIABLE;

  /** Deep copy of the string */
  ret->variable.identifier = malloc(strlen(identifier) + 1);
  strcpy(ret->variable.identifier, identifier);

  ret->variable.var_type = type;
  ret->variable.scope = scope;

  return ret;
}

symbol_t
symbol_table_create_task(const char * identifier)
{
  symbol_t ret = malloc(sizeof(union symbol));
  ret->task.type = SYMBOL_TASK;

  /** Deep copy of the string */
  ret->task.identifier = malloc(strlen(identifier) + 1);
  strcpy(ret->task.identifier, identifier);

  return ret;
}

symbol_t
symbol_table_create_global(const char * identifier, variable_type_t type)
{
  symbol_t ret = malloc(sizeof(union symbol));
  ret->global.type = SYMBOL_GLOBAL;

  /** Deep copy of the string */
  ret->global.identifier = malloc(strlen(identifier) + 1);
  strcpy(ret->global.identifier, identifier);

  ret->global.var_type = type;

  return ret;
}

bool
symbol_table_exists_variable(const char * identifier,
                             const char * scope_identifier)
{
  /** Linear search on the array */
  size_t index;
  for(index = 0; index < variables_table_size; index++) {
    if(strcmp(identifier,
              variables_table[index]->variable.identifier) == 0 &&
       strcmp(scope_identifier,
              variables_table[index]->variable.scope->identifier) == 0) {
      return true;
    }
  }
  return false;
}

bool
symbol_table_exists_task(const char * identifier)
{
  /** Linear search on the array */
  size_t index;
  for(index = 0; index < tasks_table_size; index++) {
    if(strcmp(identifier, tasks_table[index]->task.identifier) == 0) {
      return true;
    }
  }
  return false;
}

bool
symbol_table_exists_global(const char * identifier)
{
  /** Linear search on the array */
  size_t index;
  for(index = 0; index < globals_table_size; index++) {
    if(strcmp(identifier, globals_table[index]->global.identifier) == 0) {
      return true;
    }
  }
  return false;
}

variable_type_t
symbol_table_get_variable_type(const char * identifier,
                               const char * scope_identifier)
{
  /** Linear search on the array */
  size_t index;
  for(index = 0; index < variables_table_size; index++) {
    if(strcmp(identifier,
              variables_table[index]->variable.identifier) == 0 &&
       strcmp(scope_identifier,
              variables_table[index]->variable.scope->identifier) == 0) {
      return variables_table[index]->variable.var_type;
    }
  }
  return VAR_TYPE_UNSPECIF;
}

variable_type_t
symbol_table_get_global_type(const char * identifier)
{
  /** Linear search on the array */
  size_t index;
  for(index = 0; index < globals_table_size; index++) {
    if(strcmp(identifier, globals_table[index]->global.identifier) == 0) {
      return globals_table[index]->global.var_type;
    }
  }
  return VAR_TYPE_UNSPECIF;
}

static bool
symbol_table_guarantee_space(symbol_type_t table)
{
  symbol_t ** symbol_table;
  size_t table_size;

  switch(table) {
    case SYMBOL_VARIABLE:
      symbol_table = &variables_table;
      table_size = variables_table_size;
      break;
    case SYMBOL_TASK:
      symbol_table = &tasks_table;
      table_size = tasks_table_size;
      break;
    case SYMBOL_GLOBAL:
      symbol_table = &globals_table;
      table_size = globals_table_size;
      break;
  }

  if(table_size % SYM_TABLE_PREALLOC == 0) {
    *symbol_table = realloc(*symbol_table, (table_size + SYM_TABLE_PREALLOC)*sizeof(symbol_t));
    if(*symbol_table != NULL) {
      return true;
    } else {
      return false;
    }
  } else {
    return true;
  }
}

static const char *
symbol_table_var_type_to_human(variable_type_t type)
{
    switch(type) {
      case VAR_TYPE_INTEGER: return "integer";
      case VAR_TYPE_STRING: return "string";
      default: return "unspecif.";
    }
}

void
symbol_table_dump()
{
  size_t index;
  printf(":::GLOBALS:::\n");
  printf("( <identifier>, <type> ) \n\n");
  for(index = 0; index < globals_table_size; index++) {
    printf("%s, %s\n", globals_table[index]->global.identifier,
                       symbol_table_var_type_to_human(
                         globals_table[index]->global.var_type));
  }

  printf("\n\n:::VARIABLES:::\n");
  printf("( <identifier>, <type>, <scope> )\n");
  for(index = 0; index < variables_table_size; index++) {
    printf("%s, %s, %s\n", variables_table[index]->variable.identifier,
                           symbol_table_var_type_to_human(
                             variables_table[index]->variable.var_type),
                           variables_table[index]->variable.scope->identifier);
  }

  printf("\n\n:::TASKS:::\n");
  printf("( <identifier> )\n");
  for(index = 0; index < tasks_table_size; index++) {
    printf("%s\n", tasks_table[index]->task.identifier);
  }
}
