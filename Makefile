CC=gcc
CC_FLAGS=-
LEX=flex
YACC=bison

COMPILER_TARGET=tc

PARSER_DIR=parser
SCANNER_DIR=scanner
SCHEDULER_DIR=scheduler
SYMBOL_TABLE_DIR=symbol_table
AST_DIR=ast

PARSER_SRC=$(PARSER_DIR)/parser.y
SCANNER_SRC=$(SCANNER_DIR)/scanner.l
SYMBOL_TABLE_SRC=$(SYMBOL_TABLE_DIR)/symbol_table.c
AST_SRC=$(AST_DIR)/ast.c $(AST_DIR)/ast_node_print.c

PARSER_INCLUDE=-I.
SCHEDULER_INCLUDE=-I$(SCHEDULER_DIR)
SYMBOL_TABLE_INCLUDE=-I$(SYMBOL_TABLE_DIR)
AST_INCLUDE=-I$(AST_DIR)

PARSER_OUT=y.tab.c
SCANNER_OUT=lex.yy.c

all: parser scanner

	$(CC) -ly -ll \
				$(PARSER_INCLUDE)       \
				$(SCHEDULER_INCLUDE)    \
				$(SYMBOL_TABLE_INCLUDE) \
				$(AST_INCLUDE)          \
				$(SYMBOL_TABLE_SRC)     \
				$(AST_SRC)              \
				$(PARSER_OUT)           \
				$(SCANNER_OUT)					\
				-o $(COMPILER_TARGET)


parser:
	$(YACC) -d $(PARSER_SRC)

scanner:
	$(LEX) -o$(SCANNER_OUT) $(SCANNER_SRC)

clean:
	rm $(PARSER_DIR)/*.c
	rm $(PARSER_DIR)/*.h
	rm $(SCANNER_DIR)/*.c
	rm $(SYMBOL_TABLE_DIR)/*.o
	rm $(AST_DIR)/*.o

.PHONY: parser scanner all
