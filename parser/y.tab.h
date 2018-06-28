/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING = 259,
     INTEGER = 260,
     INSTRUCTION_DELIMITER = 261,
     IF_BLOCK_START = 262,
     IF_BLOCK_END = 263,
     WHILE_BLOCK_START = 264,
     WHILE_BLOCK_END = 265,
     DO_BLOCK = 266,
     SCHEDULER_START = 267,
     SCHEDULER_END = 268,
     RUN_AT = 269,
     VARIABLE_TYPE_STRING = 270,
     VARIABLE_TYPE_INTEGER = 271,
     TASK_START = 272,
     TASK_END = 273,
     BOOLEAN_CONSTANT_TRUE = 274,
     BOOLEAN_CONSTANT_FALSE = 275,
     ASSIGN_OPERATOR = 276,
     PLUS_OPERATOR = 277,
     MINUS_OPERATOR = 278,
     MUL_OPERATOR = 279,
     DIV_OPERATOR = 280,
     AND_OPERATOR = 281,
     OR_OPERATOR = 282,
     NOT_OPERATOR = 283,
     OPEN_PARENTHESIS = 284,
     CLOSE_PARENTHESIS = 285,
     SPACE = 286,
     WILDCARD = 287
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define INTEGER 260
#define INSTRUCTION_DELIMITER 261
#define IF_BLOCK_START 262
#define IF_BLOCK_END 263
#define WHILE_BLOCK_START 264
#define WHILE_BLOCK_END 265
#define DO_BLOCK 266
#define SCHEDULER_START 267
#define SCHEDULER_END 268
#define RUN_AT 269
#define VARIABLE_TYPE_STRING 270
#define VARIABLE_TYPE_INTEGER 271
#define TASK_START 272
#define TASK_END 273
#define BOOLEAN_CONSTANT_TRUE 274
#define BOOLEAN_CONSTANT_FALSE 275
#define ASSIGN_OPERATOR 276
#define PLUS_OPERATOR 277
#define MINUS_OPERATOR 278
#define MUL_OPERATOR 279
#define DIV_OPERATOR 280
#define AND_OPERATOR 281
#define OR_OPERATOR 282
#define NOT_OPERATOR 283
#define OPEN_PARENTHESIS 284
#define CLOSE_PARENTHESIS 285
#define SPACE 286
#define WILDCARD 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 7 "parser.y"
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
/* Line 1529 of yacc.c.  */
#line 137 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

