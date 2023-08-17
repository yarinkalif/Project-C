#ifndef FIRST_PASS_FUNC_H
#define FIRST_PASS_FUNC_H
#include "data.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMUM_LINE_LENGTH 80
#define WORD_SIZE 31

bool read_next_line(FILE *source_file, char *line); /* A function that reads the next line in the file */

/* Enum for error codes */
typedef enum {
    ERROR_FILE_READ,
    ERROR_EMPTY_FILE,
    ERROR_EOF_REACHED
} ErrorCode;

void handle_error(ErrorCode error_code); /* A function that handles errors while reading a line from a source file */

/* Symbol structure and global declaration */
typedef struct Symbol {
    char name[MAX_SYMBOL_LENGTH];
    int value;
    char type;  /* 'c' for code */
    struct Symbol* next;  /* Pointer to the next symbol in the list */
} Symbol;

extern Symbol* symbol_table;  /* Head of the linked list */

/* Additional function prototypes from the original revised version */
void insert_symbol(char* symbol_name, int value, char type);
char process_field(char* field);
int is_symbol(char* field);
int is_alphanumeric(char* str);
int symbol_exists(char* symbol_name);
void ensure_address_in_bounds(int address);
void memory_insert(int address, unsigned int value);
void ensure_data_in_bounds(int data);
void memory_insert_int(int address, int data);
void memory_insert_char(int address, char ch);
void handle_instruction(char* field, char* operands);

#endif /* FIRST_PASS_FUNC_H */


