#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>

enum symbol_type {
  SYMBOL_GLOBAL,
  SYMBOL_VARIABLE,
  SYMBOL_TASK,
};

enum variable_type {
  VAR_TYPE_INTEGER,
  VAR_TYPE_STRING,
  VAR_TYPE_UNSPECIF,
};

typedef enum symbol_type symbol_type_t;
typedef enum variable_type variable_type_t;

typedef struct symbol_global * symbol_global_t;
typedef struct symbol_variable * symbol_variable_t;
typedef struct symbol_task * symbol_task_t;
typedef union symbol * symbol_t;

struct symbol_base {
  symbol_type_t type;
  char * identifier;
};

struct symbol_global {
  symbol_type_t type;
  char * identifier;

  /* Global specific arguments */
  variable_type_t var_type;
};

struct symbol_task {
  symbol_type_t type;
  char * identifier;
};

struct symbol_variable {
  symbol_type_t type;
  char * identifier;

  /* Variable specific arguments */
  variable_type_t var_type;
  symbol_task_t scope;
};

union symbol {
  struct symbol_task task;
  struct symbol_variable variable;
  struct symbol_global global;
  struct symbol_base base;
};

/**
 * Adds a symbol to the symbol table
 * @method symbol_table_add_symbol
 * @param  symbol                  The symbol to add to the table
 */
void
symbol_table_add_symbol(symbol_t symbol);

/**
 * Creates a variable symbol
 * @method symbol_table_create_variable
 * @param  identifier                   The identifier of the variable
 * @param  type                         The type of the variable
 * @param  scope                        The scope of the variable
 * @return                              The created symbol
 */
 symbol_t
 symbol_table_create_variable(const char * identifier, variable_type_t type
                                                     , symbol_task_t scope);

/**
 * Creates a task symbol
 * @method symbol_table_create_task
 * @param  identifier               The identifier of the task
 * @return                          The created symbol
 */
symbol_t
symbol_table_create_task(const char * identifier);

/**
 * Creates a global symbol
 * @method symbol_table_create_global
 * @param  identifier                 The identifier of the task
 * @return                            The created symbol
 */
symbol_t
symbol_table_create_global(const char * identifier);

/**
 * Checks if a variable exists in the table for a specified scope
 * @method symbol_table_exists_variable
 * @param  identifier                    Identifier to lookup
 * @param  scope_identifier              Identifier of the scope
 * @return                               true if exists,
 *                                       false otherwise
 */
bool
symbol_table_exists_variable(const char * identifier,
                             const char * scope_identifier);

/**
 * Checks if a task exists in the table
 * @method symbol_table_exists_task
 * @param  identifier                Identifier to lookup
 * @return                           true if exists,
 *                                   false otherwise
 */
bool
symbol_table_exists_task(const char * identifier);

/**
 * Checks if a global exists in the table
 * @method symbol_table_exists_global
 * @param  identifier                  Identifier to lookup
 * @return                             true if exists,
 *                                     false otherwise
 */
bool
symbol_table_exists_global(const char * identifier);

/**
 * Returns the type of a variable
 * @method symbol_table_get_variable_type
 * @param  identifier                     Identifier of the variable
 * @param  scope_identifier               Identifier of the scope
 * @return                                The type of the variable if the
 *                                        variable exists, VAR_TYPE_UNSPECIF
 *                                        otherwise.
 */
variable_type_t
symbol_table_get_variable_type(const char * identifier,
                               const char * scope_identifier);

/**
 * Returns the type of a global
 * @method symbol_table_get_global_type
 * @param  identifier                   Identifier of the global
 * @return                              The type of the global if the global
 *                                      exists, VAR_TYPE_UNSPECIF otherwise.
 */
variable_type_t
symbol_table_get_global_type(const char * identifier);

#endif
