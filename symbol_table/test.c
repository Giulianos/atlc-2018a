#include "symbol_table.h"

int
main(int argc, char * argv[])
{
  /** Define some globals */
  symbol_table_add_symbol(
    symbol_table_create_global("variables_table_size", VAR_TYPE_INTEGER)
  );
  symbol_table_add_symbol(
    symbol_table_create_global("gl_table_size", VAR_TYPE_INTEGER)
  );
  symbol_table_add_symbol(
    symbol_table_create_global("tasks_table_size", VAR_TYPE_INTEGER)
  );
  symbol_table_add_symbol(
    symbol_table_create_global("name", VAR_TYPE_STRING)
  );

  /** Define a task and some variable*/
  symbol_t task = symbol_table_create_task("my_task1");
  symbol_table_add_symbol(task);
  symbol_table_add_symbol(
    symbol_table_create_variable("i", VAR_TYPE_INTEGER, &task->task)
  );
  symbol_table_add_symbol(
    symbol_table_create_variable("j", VAR_TYPE_INTEGER, &task->task)
  );

  /** Define a task and some variables */
  task = symbol_table_create_task("periodic_task");
  symbol_table_add_symbol(task);
  symbol_table_add_symbol(
    symbol_table_create_variable("msg", VAR_TYPE_STRING, &task->task)
  );
  symbol_table_add_symbol(
    symbol_table_create_variable("index", VAR_TYPE_INTEGER, &task->task)
  );

  symbol_table_dump();

  return 0;

}
