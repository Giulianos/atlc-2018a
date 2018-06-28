/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <symbol_table.h>
#include <ast.h>


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 189 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 202 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   104

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNRULES -- Number of states.  */
#define YYNSTATES  108

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    13,    15,    19,    23,    25,
      27,    30,    32,    38,    41,    43,    46,    49,    52,    54,
      56,    58,    61,    65,    71,    77,    81,    85,    87,    93,
      99,   101,   105,   109,   111,   113,   115,   117,   123,   129,
     132,   138,   144,   148,   151,   153,   157,   167,   169
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    39,    51,    -1,    39,    51,    -1,
      36,    35,    -1,    36,    -1,    38,     3,     6,    -1,    38,
       3,     6,    -1,    15,    -1,    16,    -1,    40,    39,    -1,
      40,    -1,    17,     3,    41,    42,    18,    -1,    37,    41,
      -1,    37,    -1,    43,    42,    -1,    49,    42,    -1,    50,
      42,    -1,    43,    -1,    49,    -1,    50,    -1,    44,     6,
      -1,     3,    21,    45,    -1,    29,    45,    22,    46,    30,
      -1,    29,    45,    23,    46,    30,    -1,    45,    22,    46,
      -1,    45,    23,    46,    -1,    46,    -1,    29,    46,    24,
      47,    30,    -1,    29,    46,    25,    47,    30,    -1,    47,
      -1,    46,    24,    47,    -1,    46,    25,    47,    -1,     5,
      -1,     3,    -1,    19,    -1,    20,    -1,    29,    48,    26,
      48,    30,    -1,    29,    48,    27,    48,    30,    -1,    28,
      48,    -1,     7,    48,    11,    42,     8,    -1,     9,    48,
      11,    42,    10,    -1,    12,    52,    13,    -1,    53,    52,
      -1,    53,    -1,     3,    14,    54,    -1,    55,    31,    55,
      31,    55,    31,    55,    31,    55,    -1,     5,    -1,    32,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    98,    98,    99,   102,   103,   106,   109,   112,   113,
     116,   117,   120,   123,   124,   127,   128,   129,   130,   131,
     132,   135,   139,   142,   143,   144,   145,   146,   149,   150,
     151,   152,   153,   156,   157,   161,   162,   163,   164,   165,
     168,   171,   175,   178,   179,   182,   185,   193,   194
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "INTEGER",
  "INSTRUCTION_DELIMITER", "IF_BLOCK_START", "IF_BLOCK_END",
  "WHILE_BLOCK_START", "WHILE_BLOCK_END", "DO_BLOCK", "SCHEDULER_START",
  "SCHEDULER_END", "RUN_AT", "VARIABLE_TYPE_STRING",
  "VARIABLE_TYPE_INTEGER", "TASK_START", "TASK_END",
  "BOOLEAN_CONSTANT_TRUE", "BOOLEAN_CONSTANT_FALSE", "ASSIGN_OPERATOR",
  "PLUS_OPERATOR", "MINUS_OPERATOR", "MUL_OPERATOR", "DIV_OPERATOR",
  "AND_OPERATOR", "OR_OPERATOR", "NOT_OPERATOR", "OPEN_PARENTHESIS",
  "CLOSE_PARENTHESIS", "SPACE", "WILDCARD", "$accept", "program",
  "globals", "global", "variable", "var_type", "tasks", "task",
  "variables", "code", "instruction", "assignment", "arithmetic", "term",
  "factor", "boolean", "if_block", "while_block", "scheduler",
  "scheduled_tasks", "scheduled_task", "cron_rule", "cron_value", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    36,    37,    38,    38,
      39,    39,    40,    41,    41,    42,    42,    42,    42,    42,
      42,    43,    44,    45,    45,    45,    45,    45,    46,    46,
      46,    46,    46,    47,    47,    48,    48,    48,    48,    48,
      49,    50,    51,    52,    52,    53,    54,    55,    55
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     3,     3,     1,     1,
       2,     1,     5,     2,     1,     2,     2,     2,     1,     1,
       1,     2,     3,     5,     5,     3,     3,     1,     5,     5,
       1,     3,     3,     1,     1,     1,     1,     5,     5,     2,
       5,     5,     3,     2,     1,     3,     9,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     9,     0,     0,     0,     5,     0,     0,    11,
       0,     1,     0,     4,     0,     0,     3,    10,    14,     0,
       0,     2,     6,     0,     0,    44,    13,     0,     0,     0,
       0,     0,    18,     0,    19,    20,     0,    42,    43,     7,
       0,    35,    36,     0,     0,     0,     0,    12,    15,    21,
      16,    17,    47,    48,    45,     0,    34,    33,     0,    22,
      27,    30,    39,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    31,    32,     0,     0,    40,
      41,     0,    25,    26,    31,    32,     0,    37,    38,     0,
      23,    24,    28,    29,     0,     0,     0,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    18,     7,     8,     9,    20,    31,
      32,    33,    59,    60,    61,    45,    34,    35,    16,    24,
      25,    54,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -66
static const yytype_int8 yypact[] =
{
      44,   -66,   -66,    34,    30,    28,     2,    53,    52,    28,
       2,   -66,    52,   -66,    47,    64,   -66,   -66,     2,    69,
      39,   -66,   -66,    33,    60,    64,   -66,    70,    56,    -8,
      -8,    61,    39,    72,    39,    39,    -3,   -66,   -66,   -66,
       4,   -66,   -66,    -8,    -8,    71,    73,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,    54,   -66,   -66,     4,    40,
      41,   -66,   -66,    42,    39,    39,    -3,    48,    50,     5,
       5,    35,    35,    -8,    -8,    75,    76,    57,     5,     5,
      35,    35,     5,    41,    41,   -66,   -66,    51,    59,   -66,
     -66,    -3,    25,    27,    62,    63,    50,   -66,   -66,    65,
     -66,   -66,   -66,   -66,    -3,    66,    -3,   -66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,    74,   -66,   -66,     9,    49,   -66,    77,   -29,
     -66,   -66,    29,   -54,   -49,   -30,   -66,   -66,    78,    79,
     -66,   -66,   -65
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      46,    77,    52,    48,    68,    50,    51,    56,    56,    57,
      57,    41,    42,    62,    63,    83,    84,     1,     2,    19,
      43,    44,    85,    86,    92,    93,    99,    19,    96,    53,
      11,    94,    95,    58,    82,    75,    76,    10,    56,   105,
      57,   107,    28,    87,    88,     3,    29,    36,    30,    71,
      72,    71,    72,    22,    12,   100,    14,   101,    17,     1,
       2,     3,    69,    70,    15,    71,    72,    23,    73,    74,
      78,    79,    27,    37,    80,    81,    39,    40,    49,    47,
      13,    97,    64,    89,    65,    66,    90,    67,    91,    98,
      21,     0,   102,   103,     0,    26,   104,   106,     0,     0,
       0,     0,     0,     0,    38
};

static const yytype_int8 yycheck[] =
{
      30,    66,     5,    32,    58,    34,    35,     3,     3,     5,
       5,    19,    20,    43,    44,    69,    70,    15,    16,    10,
      28,    29,    71,    72,    78,    79,    91,    18,    82,    32,
       0,    80,    81,    29,    29,    64,    65,     3,     3,   104,
       5,   106,     3,    73,    74,    17,     7,    14,     9,    24,
      25,    24,    25,     6,     5,    30,     3,    30,     9,    15,
      16,    17,    22,    23,    12,    24,    25,     3,    26,    27,
      22,    23,     3,    13,    24,    25,     6,    21,     6,    18,
       6,    30,    11,     8,    11,    31,    10,    58,    31,    30,
      12,    -1,    30,    30,    -1,    18,    31,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    16,    17,    34,    35,    36,    38,    39,    40,
       3,     0,    39,    35,     3,    12,    51,    39,    37,    38,
      41,    51,     6,     3,    52,    53,    41,     3,     3,     7,
       9,    42,    43,    44,    49,    50,    14,    13,    52,     6,
      21,    19,    20,    28,    29,    48,    48,    18,    42,     6,
      42,    42,     5,    32,    54,    55,     3,     5,    29,    45,
      46,    47,    48,    48,    11,    11,    31,    45,    46,    22,
      23,    24,    25,    26,    27,    42,    42,    55,    22,    23,
      24,    25,    29,    46,    46,    47,    47,    48,    48,     8,
      10,    31,    46,    46,    47,    47,    46,    30,    30,    55,
      30,    30,    30,    30,    31,    55,    31,    55
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 98 "parser.y"
    { %% = ast_program_new((yyvsp[(1) - (3)].global_list),(yyvsp[(2) - (3)].task_list),(yyvsp[(3) - (3)].scheduler)); }
    break;

  case 3:
#line 99 "parser.y"
    { %% = ast_program_new(NULL,(yyvsp[(1) - (2)].task_list),(yyvsp[(2) - (2)].scheduler)); }
    break;

  case 4:
#line 102 "parser.y"
    { %% = ast_globals_add((yyvsp[(2) - (2)].global_list), (yyvsp[(1) - (2)].global)); }
    break;

  case 5:
#line 103 "parser.y"
    { %% = ast_globals_new((yyvsp[(1) - (1)].global)); }
    break;

  case 6:
#line 106 "parser.y"
    { symbol_table_add_symbol(symbol_table_create_global((yyvsp[(2) - (3)].identifier), (yyvsp[(1) - (3)].var_type))); (yyval.global) = ast_global_new((yyvsp[(2) - (3)].identifier)); }
    break;

  case 7:
#line 109 "parser.y"
    { symbol_table_add_symbol(symbol_table_create_variable((yyvsp[(2) - (3)].identifier), (yyvsp[(1) - (3)].var_type), NULL)); (yyval.variable) = ast_variable_new((yyvsp[(2) - (3)].identifier)); }
    break;

  case 8:
#line 112 "parser.y"
    { (yyval.var_type) = VAR_TYPE_STRING }
    break;

  case 9:
#line 113 "parser.y"
    { (yyval.var_type) = VAR_TYPE_INTEGER }
    break;

  case 10:
#line 116 "parser.y"
    { %% = ast_tasks_add((yyvsp[(2) - (2)].task_list),(yyvsp[(1) - (2)].task)); }
    break;

  case 11:
#line 117 "parser.y"
    { %% = ast_tasks_new((yyvsp[(1) - (1)].task)); }
    break;

  case 12:
#line 120 "parser.y"
    { symbol_table_add_symbol(symbol_table_create_task((yyvsp[(2) - (5)].identifier))); (yyval.task) = ast_task_new((yyvsp[(2) - (5)].identifier),(yyvsp[(3) - (5)].variable_list),(yyvsp[(4) - (5)].code)); }
    break;

  case 13:
#line 123 "parser.y"
    { %% = ast_variables_add((yyvsp[(2) - (2)].variable_list), (yyvsp[(1) - (2)].variable)); }
    break;

  case 14:
#line 124 "parser.y"
    { %% = ast_variables_new((yyvsp[(1) - (1)].variable)); }
    break;

  case 15:
#line 127 "parser.y"
    { ast_code_add((yyvsp[(2) - (2)].code),(ast_code_child_t)(yyvsp[(1) - (2)].instruction)); }
    break;

  case 16:
#line 128 "parser.y"
    { ast_code_add((yyvsp[(2) - (2)].code),(ast_code_child_t)(yyvsp[(1) - (2)].if_block)); }
    break;

  case 17:
#line 129 "parser.y"
    { ast_code_add((yyvsp[(2) - (2)].code),(ast_code_child_t)(yyvsp[(1) - (2)].while_block)); }
    break;

  case 18:
#line 130 "parser.y"
    { ast_code_new((ast_code_child_t)(yyvsp[(1) - (1)].instruction)); }
    break;

  case 19:
#line 131 "parser.y"
    { ast_code_new((ast_code_child_t)(yyvsp[(1) - (1)].if_block)); }
    break;

  case 20:
#line 132 "parser.y"
    { ast_code_new((ast_code_child_t)(yyvsp[(1) - (1)].while_block)); }
    break;

  case 21:
#line 135 "parser.y"
    { (yyval.instruction) = (ast_code_child_t)(yyvsp[(1) - (2)].assignment); }
    break;

  case 22:
#line 139 "parser.y"
    { (yyval.assignment) = ast_assignment_new((yyvsp[(1) - (3)].identifier),(yyvsp[(3) - (3)].arithmetic)); }
    break;

  case 23:
#line 142 "parser.y"
    { (yyval.arithmetic) = ast_arithmetic_new(AST_ARIT_SUM,(yyvsp[(2) - (5)].arithmetic),(yyvsp[(4) - (5)].arithmetic),NULL,0); }
    break;

  case 24:
#line 143 "parser.y"
    { (yyval.arithmetic) = ast_arithmetic_new(AST_ARIT_DIF,(yyvsp[(2) - (5)].arithmetic),(yyvsp[(4) - (5)].arithmetic),NULL,0); }
    break;

  case 25:
#line 144 "parser.y"
    { (yyval.arithmetic) = ast_arithmetic_new(AST_ARIT_SUM,(yyvsp[(1) - (3)].arithmetic),(yyvsp[(3) - (3)].arithmetic),NULL,0); }
    break;

  case 26:
#line 145 "parser.y"
    { (yyval.arithmetic) = ast_arithmetic_new(AST_ARIT_DIF,(yyvsp[(1) - (3)].arithmetic),(yyvsp[(3) - (3)].arithmetic),NULL,0); }
    break;

  case 27:
#line 146 "parser.y"
    { (yyval.arithmetic) = (yyvsp[(1) - (1)].arithmetic); }
    break;

  case 28:
#line 149 "parser.y"
    { (yyval.arithmetic) = ast_arithmetic_new(AST_ARIT_PROD,(yyvsp[(2) - (5)].arithmetic),(yyvsp[(4) - (5)].arithmetic),NULL,0); }
    break;

  case 29:
#line 150 "parser.y"
    { (yyval.arithmetic) = ast_arithmetic_new(AST_ARIT_DIV,(yyvsp[(2) - (5)].arithmetic),(yyvsp[(4) - (5)].arithmetic),NULL,0); }
    break;

  case 30:
#line 151 "parser.y"
    { (yyval.arithmetic) = (yyvsp[(1) - (1)].arithmetic); }
    break;

  case 31:
#line 152 "parser.y"
    { (yyval.arithmetic) = ast_arithmetic_new(AST_ARIT_DIV,(yyvsp[(1) - (3)].arithmetic),(yyvsp[(3) - (3)].arithmetic),NULL,0); }
    break;

  case 32:
#line 153 "parser.y"
    { (yyval.arithmetic) = ast_arithmetic_new(AST_ARIT_DIV,(yyvsp[(1) - (3)].arithmetic),(yyvsp[(3) - (3)].arithmetic),NULL,0); }
    break;

  case 33:
#line 156 "parser.y"
    { (yyval.arithmetic) = ast_arithmetic_new(AST_ARIT_CONST,NULL,NULL,NULL,(yyvsp[(1) - (1)].number)); }
    break;

  case 34:
#line 157 "parser.y"
    { (yyval.arithmetic) = ast_arithmetic_new(AST_ARIT_CONST,NULL,NULL,(yyvsp[(1) - (1)].identifier),0); }
    break;

  case 35:
#line 161 "parser.y"
    { (yyval.boolean) = ast_boolean_new(AST_BOOL_TRUE,NULL,NULL); }
    break;

  case 36:
#line 162 "parser.y"
    { (yyval.boolean) = ast_boolean_new(AST_BOOL_FALSE,NULL,NULL); }
    break;

  case 37:
#line 163 "parser.y"
    { (yyval.boolean) = ast_boolean_new(AST_BOOL_AND,(yyvsp[(2) - (5)].boolean),(yyvsp[(4) - (5)].boolean)); }
    break;

  case 38:
#line 164 "parser.y"
    { (yyval.boolean) = ast_boolean_new(AST_BOOL_OR,(yyvsp[(2) - (5)].boolean),(yyvsp[(4) - (5)].boolean)); }
    break;

  case 39:
#line 165 "parser.y"
    { (yyval.boolean) = ast_boolean_new(AST_BOOL_NOT,(yyvsp[(2) - (2)].boolean),NULL); }
    break;

  case 40:
#line 168 "parser.y"
    { (yyval.if_block) = ast_if_block_new((yyvsp[(2) - (5)].boolean),(yyvsp[(4) - (5)].code)); }
    break;

  case 41:
#line 171 "parser.y"
    { (yyval.while_block) = ast_while_block_new((yyvsp[(2) - (5)].boolean),(yyvsp[(4) - (5)].code)); }
    break;

  case 42:
#line 175 "parser.y"
    { (yyval.scheduler) = (yyvsp[(2) - (3)].scheduler) }
    break;

  case 43:
#line 178 "parser.y"
    { (yyval.scheduler) = ast_scheduler_add((yyvsp[(2) - (2)].scheduler),(yyvsp[(1) - (2)].scheduled_task)); }
    break;

  case 44:
#line 179 "parser.y"
    { (yyval.scheduler) = ast_scheduler_new((yyvsp[(1) - (1)].scheduled_task)); }
    break;

  case 45:
#line 182 "parser.y"
    { (yyval.scheduled_task) = ast_scheduled_task_new((yyvsp[(1) - (3)].identifier),(yyvsp[(3) - (3)].crontab_rule)); }
    break;

  case 46:
#line 185 "parser.y"
    { (yyval.crontab_rule) = malloc(crontab_rule_t);
                                                                                                       (yyval.crontab_rule)[CRON_MINUTE] = (yyvsp[(1) - (9)].number);
                                                                                                       (yyval.crontab_rule)[CRON_HOUR] = (yyvsp[(3) - (9)].number);
                                                                                                       (yyval.crontab_rule)[CRON_MONTH_DAY] = (yyvsp[(5) - (9)].number);
                                                                                                       (yyval.crontab_rule)[CRON_MONTH] = (yyvsp[(7) - (9)].number);
                                                                                                       (yyval.crontab_rule)[CRON_WEEK_DAY] = (yyvsp[(9) - (9)].number);}
    break;

  case 47:
#line 193 "parser.y"
    { (yyval.number) = (yyvsp[(1) - (1)].number); }
    break;

  case 48:
#line 194 "parser.y"
    { (yyval.number) = -1; }
    break;


/* Line 1267 of yacc.c.  */
#line 1725 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



