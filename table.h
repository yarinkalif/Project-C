#ifndef _TABLE_H
#define _TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "errors.h"

#define TABLE_SIZE 80

/**
 * @struct macro
 * @brief Structure representing a macro.
 *
 * This structure represents a single macro, which has a name, 
 * content and a pointer to the next macro (to form a linked list).
 */
typedef struct macro {
	char *macroName;
	char *macroContent;
	struct macro *next;
} macro;

/**
 * @struct macro_table
 * @brief Structure representing a table (linked list) of macros.
 *
 * This structure represents the head of a linked list containing
 * macro structures.
 */
typedef struct {
	macro *head;
} macro_table;

/**
 * @struct s_table
 * @brief Structure representing a symbol table.
 *
 * This structure represents a simple symbol table, where each
 * entry is a string.
 */
typedef struct s_table{
	char **entries;
} s_table;

/**
 * @struct s_table_entry
 * @brief Structure representing an entry in the symbols table.
 *
 * This structure represents a detailed entry for the symbols table,
 * containing the symbol's name, address, type and a pointer to 
 * the next symbol entry.
 */
typedef struct s_table_entry{
	char *symbol;
	int symbol_addr;
	symbol_type symbol_type;
	struct s_table_entry *next;
} s_table_entry;

/**
 * @struct Symbol
 * @brief Structure representing a symbol.
 *
 * This structure represents a detailed symbol with its name, value, 
 * type and a pointer to the next symbol.
 */
typedef struct {
	char name[MAX_SYMBOL_LENGTH];
	int value;
	char type;
	struct Symbol* next;
} Symbol;

/**
 * @struct SymbolTable
 * @brief Structure representing a table of symbols.
 *
 * This structure contains an array of symbols and a count 
 * indicating the number of symbols currently in the table.
 */
typedef struct {
    Symbol symbols[MAX_SYMBOL_LENGTH];
    int count;
} SymbolTable;

/**
 * @var symbol_table
 * @brief Global symbol table variable.
 */
SymbolTable symbol_table; 

/**
 * @brief Creates a new macro table (linked list).
 *
 * @return A pointer to the newly created macro table.
 */
macro_table *create_macro_table();

/**
 * @brief Adds a new macro to the macro table.
 *
 * @param table The macro table to which the new macro will be added.
 * @param name The name of the new macro.
 * @param content The content of the new macro.
 */
void add_macro_to_table(macro_table *table, char *name, char *content);

/**
 * @brief Replaces macro names in a given line with their content.
 *
 * @param line The line to search and replace macros in.
 * @param table The macro table containing defined macros.
 * @return A string with macros expanded, or the original line.
 */
char *expend_macro(char *line, macro_table *table);

/**
 * @brief Frees memory used by the macro table.
 *
 * @param table The macro table to be freed.
 */
void free_macro_table(macro_table *table);

/**
 * @brief Creates a new symbol table.
 *
 * @return A pointer to the newly created symbol table.
 */
s_table *create_symbol_table();

#endif
