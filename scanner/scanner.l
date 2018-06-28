%{
#include <symbol_table.h>
#include <ast_node_types.h>
#include <ast.h>
#include <symbol_table.h>
#include <y.tab.h>
%}

STRING                   ["][^"\n\r]*["]
INTEGER                  [-]?[0-9]+
INSTRUCTION_DELIMITER    ";"
IF_BLOCK_START           "IF"
IF_BLOCK_END             "ENDIF"
WHILE_BLOCK_START        "WHILE"
WHILE_BLOCK_END          "ENDWHILE"
DO_BLOCK                 "DO"
SCHEDULER_START          "SCHEDULE"
SCHEDULER_END            "ENDSCHEDULE"
RUN_AT                   "@"
VARIABLE_TYPE_STRING     "string"
VARIABLE_TYPE_INTEGER    "integer"
TASK_START               "TASK"
TASK_END                 "ENDTASK"
BOOLEAN_CONSTANT_TRUE    "true"|"TRUE"
BOOLEAN_CONSTANT_FALSE   "false"|"FALSE"
ASSIGN_OPERATOR          "="
PLUS_OPERATOR            "+"
MINUS_OPERATOR           "-"
MUL_OPERATOR             "*"
DIV_OPERATOR             "/"
AND_OPERATOR             "&"
OR_OPERATOR              "|"
NOT_OPERATOR             "!"
OPEN_PARENTHESIS         "("
CLOSE_PARENTHESIS        ")"
SPACE                    " "
IDENTIFIER               [A-Za-z][0-9A-Za-z_]*

%%

{STRING}                   { yylval.string = yytext;
                             return STRING;
                           }

{INTEGER}                  { yylval.number = atoi(yytext);
						                 return INTEGER;
                           }

{INSTRUCTION_DELIMITER}    return INSTRUCTION_DELIMITER;
{IF_BLOCK_START}           return IF_BLOCK_START;
{IF_BLOCK_END}             return IF_BLOCK_END;
{WHILE_BLOCK_START}        return WHILE_BLOCK_START;
{WHILE_BLOCK_END}          return WHILE_BLOCK_END;
{DO_BLOCK}                 return DO_BLOCK;
{SCHEDULER_START}          return SCHEDULER_START;
{SCHEDULER_END}            return SCHEDULER_END;
{RUN_AT}                   return RUN_AT;
{VARIABLE_TYPE_STRING}     return VARIABLE_TYPE_STRING;
{VARIABLE_TYPE_INTEGER}    return VARIABLE_TYPE_INTEGER;
{TASK_START}               return TASK_START;
{TASK_END}                 return TASK_END;
{BOOLEAN_CONSTANT_TRUE}    return BOOLEAN_CONSTANT_TRUE;
{BOOLEAN_CONSTANT_FALSE}   return BOOLEAN_CONSTANT_FALSE;
{ASSIGN_OPERATOR}          return ASSIGN_OPERATOR;
{PLUS_OPERATOR}            return PLUS_OPERATOR;
{MINUS_OPERATOR}           return MINUS_OPERATOR;
{MUL_OPERATOR}             return MUL_OPERATOR;
{DIV_OPERATOR}             return DIV_OPERATOR;
{AND_OPERATOR}             return AND_OPERATOR;
{OR_OPERATOR}              return OR_OPERATOR;
{NOT_OPERATOR}             return NOT_OPERATOR;
{OPEN_PARENTHESIS}         return OPEN_PARENTHESIS;
{CLOSE_PARENTHESIS}        return CLOSE_PARENTHESIS;
{SPACE}                    return SPACE;

<<EOF>>					           return 0;

{IDENTIFIER}               { yylval.identifier = yytext;
                             return IDENTIFIER;
                           }

%%
