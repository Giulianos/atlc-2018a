%{
#include <symbol_table.h>
#include <ast_node_types.h>
#include <ast.h>
#include <ast_node_print.h>
int yylex();
int yyerror();
%}

%union
{
  int number;
  char * identifier;
  char * string;
  ast_program_t program;
  ast_globals_t global_list;
  ast_global_t global;
  ast_tasks_t task_list;
  ast_task_t task;
  ast_variables_t variable_list;
  ast_variable_t variable;
  ast_code_t code;
  ast_assignment_t assignment;
  ast_arithmetic_t arithmetic;
  ast_if_block_t if_block;
  ast_while_block_t while_block;
  ast_boolean_t boolean;
  ast_scheduler_t scheduler;
  ast_scheduled_task_t scheduled_task;
  ast_code_child_t  instruction;
  variable_type_t  var_type;
  crontab_rule_t crontab_rule;
}

%start program

%token <identifier> IDENTIFIER;
%token <string> STRING;
%token <number> INTEGER;

%token INSTRUCTION_DELIMITER;

%token IF_BLOCK_START;
%token IF_BLOCK_END;

%token WHILE_BLOCK_START;
%token WHILE_BLOCK_END;

%token DO_BLOCK;

%token SCHEDULER_START;
%token SCHEDULER_END;

%token RUN_AT;

%token VARIABLE_TYPE_STRING;
%token VARIABLE_TYPE_INTEGER;

%token TASK_START;
%token TASK_END;

%token BOOLEAN_CONSTANT_TRUE;
%token BOOLEAN_CONSTANT_FALSE;

%token ASSIGN_OPERATOR;
%token PLUS_OPERATOR;
%token MINUS_OPERATOR;
%token MUL_OPERATOR;
%token DIV_OPERATOR;
%token AND_OPERATOR;
%token OR_OPERATOR;
%token NOT_OPERATOR;

%token OPEN_PARENTHESIS;
%token CLOSE_PARENTHESIS;

%token SPACE;
%token WILDCARD;

%type  <program>        program
%type  <global_list>    globals
%type  <global>         global
%type  <task_list>      tasks
%type  <task>           task
%type  <variable_list>  variables
%type  <variable>       variable
%type  <code>           code
%type  <instruction>    instruction
%type  <assignment>     assignment
%type  <arithmetic>     arithmetic term factor
%type  <if_block>       if_block
%type  <while_block>     while_block
%type  <boolean>        boolean
%type  <scheduler>      scheduler scheduled_tasks
%type  <scheduled_task> scheduled_task
%type  <var_type>       var_type
%type  <crontab_rule>   cron_rule
%type  <number>         cron_value

%%

program             : globals tasks scheduler       { $$ = ast_program_new($1,$2,$3); }
                    | tasks scheduler               { $$ = ast_program_new(NULL,$1,$2); }
                    ;

globals             : global globals                { $$ = ast_globals_add($2, $1); }
                    | global                        { $$ = ast_globals_new($1); }
                    ;

global              : var_type IDENTIFIER INSTRUCTION_DELIMITER { symbol_table_add_symbol(symbol_table_create_global($2, $1)); $$ = ast_global_new($2); }
                    ;

variable            : var_type IDENTIFIER INSTRUCTION_DELIMITER { symbol_table_add_symbol(symbol_table_create_variable($2, $1, NULL)); $$ = ast_variable_new($2); }
                    ;

var_type            : VARIABLE_TYPE_STRING { $$ = VAR_TYPE_STRING; }
                    | VARIABLE_TYPE_INTEGER { $$ = VAR_TYPE_INTEGER; }
                    ;

tasks               : task tasks { $$ = ast_tasks_add($2,$1); }
                    | task { $$ = ast_tasks_new($1); }
                    ;

task                : TASK_START IDENTIFIER variables code TASK_END { symbol_table_add_symbol(symbol_table_create_task($2)); $$ = ast_task_new($2,$3,$4); }
                    ;

variables           : variable variables              { $$ = ast_variables_add($2, $1); }
                    | variable                        { $$ = ast_variables_new($1); }
                    ;

code                : instruction code { ast_code_add($2,(ast_code_child_t)$1); }
                    | if_block code    { ast_code_add($2,(ast_code_child_t)$1); }
                    | while_block code { ast_code_add($2,(ast_code_child_t)$1); }
                    | instruction      { ast_code_new((ast_code_child_t)$1); }
                    | if_block         { ast_code_new((ast_code_child_t)$1); }
                    | while_block      { ast_code_new((ast_code_child_t)$1); }
                    ;

instruction         : assignment INSTRUCTION_DELIMITER { $$ = (ast_code_child_t)$1; }
                    ;


assignment          : IDENTIFIER ASSIGN_OPERATOR arithmetic   { $$ = ast_assignment_new($1,$3); }
                    ;

arithmetic          : OPEN_PARENTHESIS arithmetic PLUS_OPERATOR term CLOSE_PARENTHESIS   { $$ = ast_arithmetic_new(AST_ARIT_SUM,$2,$4,NULL,0); }
                    | OPEN_PARENTHESIS arithmetic MINUS_OPERATOR term CLOSE_PARENTHESIS  { $$ = ast_arithmetic_new(AST_ARIT_DIF,$2,$4,NULL,0); }
                    | arithmetic PLUS_OPERATOR term                                      { $$ = ast_arithmetic_new(AST_ARIT_SUM,$1,$3,NULL,0); }
                    | arithmetic MINUS_OPERATOR term                                     { $$ = ast_arithmetic_new(AST_ARIT_DIF,$1,$3,NULL,0); }
                    | term                                                               { $$ = $1; }
                    ;

term                : OPEN_PARENTHESIS term MUL_OPERATOR factor CLOSE_PARENTHESIS        { $$ = ast_arithmetic_new(AST_ARIT_PROD,$2,$4,NULL,0); }
                    | OPEN_PARENTHESIS term DIV_OPERATOR factor CLOSE_PARENTHESIS        { $$ = ast_arithmetic_new(AST_ARIT_DIV,$2,$4,NULL,0); }
                    | factor                                                             { $$ = $1; }
                    | term MUL_OPERATOR factor                                           { $$ = ast_arithmetic_new(AST_ARIT_DIV,$1,$3,NULL,0); }
                    | term DIV_OPERATOR factor                                           { $$ = ast_arithmetic_new(AST_ARIT_DIV,$1,$3,NULL,0); }
                    ;

factor              : INTEGER           { $$ = ast_arithmetic_new(AST_ARIT_CONST,NULL,NULL,NULL,$1); }
                    | IDENTIFIER        { $$ = ast_arithmetic_new(AST_ARIT_CONST,NULL,NULL,$1,0); }
                    ;


boolean             : BOOLEAN_CONSTANT_TRUE                                                 { $$ = ast_boolean_new(AST_BOOL_TRUE,NULL,NULL); }
                    | BOOLEAN_CONSTANT_FALSE                                                { $$ = ast_boolean_new(AST_BOOL_FALSE,NULL,NULL); }
                    | OPEN_PARENTHESIS boolean AND_OPERATOR boolean CLOSE_PARENTHESIS       { $$ = ast_boolean_new(AST_BOOL_AND,$2,$4); }
                    | OPEN_PARENTHESIS boolean OR_OPERATOR boolean CLOSE_PARENTHESIS        { $$ = ast_boolean_new(AST_BOOL_OR,$2,$4); }
                    | NOT_OPERATOR boolean                                                  { $$ = ast_boolean_new(AST_BOOL_NOT,$2,NULL); }
                    ;

if_block            : IF_BLOCK_START boolean DO_BLOCK code IF_BLOCK_END             { $$ = ast_if_block_new($2,$4); }
                    ;

while_block         : WHILE_BLOCK_START boolean DO_BLOCK code WHILE_BLOCK_END       { $$ = ast_while_block_new($2,$4); }
                    ;


scheduler           : SCHEDULER_START scheduled_tasks SCHEDULER_END                 { $$ = $2; }
                    ;

scheduled_tasks     : scheduled_task scheduled_tasks                                { $$ = ast_scheduler_add($2,$1); }
                    | scheduled_task                                                { $$ = ast_scheduler_new($1); }
                    ;

scheduled_task      : IDENTIFIER RUN_AT cron_rule                                   { $$ = ast_scheduled_task_new($1,$3); }
                    ;

cron_rule           : cron_value SPACE cron_value SPACE cron_value SPACE cron_value SPACE cron_value { $$[CRON_MINUTE] = $1;
                                                                                                       $$[CRON_HOUR] = $3;
                                                                                                       $$[CRON_MONTH_DAY] = $5;
                                                                                                       $$[CRON_MONTH] = $7;
                                                                                                       $$[CRON_WEEK_DAY] = $9;}
                    ;

cron_value          : INTEGER       { $$ = $1; }
                    | MUL_OPERATOR  { $$ = -1; }
                    ;
