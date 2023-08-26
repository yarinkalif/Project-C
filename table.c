#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

/**
 * @brief Creates a new macro table (linked list).
 *
 * This function initializes a new macro table structure, which is 
 * essentially a linked list of macro entries. 
 *
 * @return A pointer to the newly created macro table, or NULL if 
 * memory allocation fails.
 */
macro_table *create_macro_table() {
	macro_table *table = (macro_table*)malloc(sizeof(macro_table));
	if (table == NULL){ /*check if the memory allocation successed*/
		return NULL;
	}
	table->head = NULL;
	return table;
}

/**
 * @brief Adds a new macro to the macro table.
 * 
 * This function creates a new macro entry with the given name and 
 * content, then prepends it to the provided macro table's linked list.
 *
 * @param table The macro table to which the new macro will be added.
 * @param name The name of the new macro.
 * @param content The content of the new macro.
 */
void add_macro_to_table(macro_table *table, char *name, char *content) {
	macro *newMacro = (macro*) malloc(sizeof(macro)); /*create new space in the table for new macro*/

	newMacro->macroName = (char*)malloc((strlen(name) + 1)*sizeof(char)); /*allocate memory for name*/
	strcpy(newMacro->macroName,name); /*copy the macro name*/
	newMacro->macroContent = (char*)malloc((strlen(content) + 1)*sizeof(char)); /*allocate memory for content*/
	strcpy(newMacro->macroContent,content); /*copy the macro content*/
	newMacro->next = table->head; /*linked the new macro to the beginning of the list*/
	table->head = newMacro;
}

/**
 * @brief Replaces macro names in a given line with their content.
 *
 * This function searches for macro names in the provided line 
 * and replaces them with the content of the macro (if found 
 * in the macro table).
 *
 * @param line The line of code to search and replace macros in.
 * @param table The macro table containing defined macros.
 * @return A new string with macros expanded, or the original 
 * line if no macros were found. Returns NULL if memory allocation fails.
 */
char *expend_macro(char *line, macro_table *table) {
	macro *curr = table->head; /*pointed to the head of the linked list*/
	char *expendLine = (char *)malloc(MAX_LENGTH_LINE + 2);

	if (expendLine == NULL) {
		return NULL;
	}
	strcpy(expendLine, line);

	while (curr != NULL){
		char *macroPos = strstr(expendLine, curr->macroName); /*search for the macro name in the linked list*/
		if (macroPos != NULL) { /*found the macro name*/
			strcpy(macroPos, curr->macroContent); /*replace the line with the macro content*/
			return expendLine;
		}
		curr = curr->next;
	}
	return expendLine;
}
	
/**
 * @brief Frees all memory used by the macro table.
 *
 * This function deallocates memory used by the macro table 
 * and all its entries.
 *
 * @param table The macro table to be freed.
 */
void free_macro_table(macro_table *table) {
	macro *curr = table->head;
	while (curr != NULL) {
		macro *temp = curr;
		curr = curr->next;
		free(temp->macroName);
		free(temp->macroContent);
		free(temp);
	}
}

/**
 * @brief Creates a new symbol table.
 *
 * This function initializes a new symbol table structure with 
 * predefined table size. Each entry is initialized to NULL.
 *
 * @return A pointer to the newly created symbol table.
 */

s_table *create_symbol_table() {
	int i=0;
	s_table *symbolTable = malloc(sizeof(s_table));
	symbolTable->entries = malloc(sizeof(s_table_entry) * TABLE_SIZE);
	for (i=0; i<TABLE_SIZE; i++) {
		symbolTable->entries[i] = NULL;
	}
	return symbolTable;
}
