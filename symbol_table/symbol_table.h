#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

enum symbol_type {
  SYMBOL_GLOBAL,
  SYMBOL_VARIABLE,
  SYMBOL_TASK,
};

enum variable_type {
  VAR_TYPE_INTEGER,
  VAR_TYPE_STRING,
};

typedef enum symbol_type symbol_type_t;
typedef enum variable_type variable_type_t;

struct symbol_variable {
  symbol_type_t type;
  char * identifier;

  /* Global specific arguments */
  const variable_type_t var_type;
};

struct symbol_variable {
  symbol_type_t type;
  char * identifier;

  /* Variable specific arguments */
  const variable_type_t var_type;
  symbol_task_t scope;
};

struct symbol_task {
  symbol_type_t type;
  char * identifier;
};

union symbol {
  symbol_task task;
  symbol_variable variable;
};

typedef struct symbol_variable * symbol_variable_t;
typedef struct symbol_task * symbol_task_t;
typedef union symbol * symbol_t;

/**
 * Adds a symbol to the symbol table
 * @method symbol_table_add_symbol
 * @param  symbol                  The symbol to add to the table
 */
void symbol_table_add_symbol(symbol_t symbol);

/**
 * Creates a variable symbol
 * @method symbol_table_create_variable
 * @param  identifier                   The identifier of the variable
 * @param  type                         The type of the variable
 * @param  scope                        The scope of the variable
 * @return                              The created symbol
 */
symbol_t symbol_table_create_variable(const char * identifier,
                                      variable_type_t type
                                      symbol_task_t scope);

/**
 * Creates a task symbol
 * @method symbol_table_create_task
 * @param  identifier               The identifier of the task
 * @return                          The created symbol
 */
symbol_t symbol_table_create_task(const char * identifier);

/**
 * Creates a global symbol
 * @method symbol_table_create_global
 * @param  identifier                 The identifier of the task
 * @return                            The created symbol
 */
symbol_t symbol_table_create_global(const char * identifier);

/**
 * Checks if a variable exists in the table for a specified scope
 * @method symbol_table_exists_variable
 * @param  identifier                    Identifier to lookup
 * @param  scope_identifier              Identifier of the scope
 * @return                               true if exists,
 *                                       false otherwise
 */
bool symbol_table_exists_variable(const char * identifier,
                                  const char * scope_identifier);

/**
 * Checks if a task exists in the table
 * @method symbol_table_exists_task
 * @param  identifier                Identifier to lookup
 * @return                           true if exists,
 *                                   false otherwise
 */
bool symbol_table_exists_task(const char * identifier);

/**
 * Checks if a global exists in the table
 * @method symbol_table_exists_global
 * @param  identifier                  Identifier to lookup
 * @return                             true if exists,
 *                                     false otherwise
 */
bool symbol_table_exists_global(const char * identifier);


#endif
