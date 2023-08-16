#include "data.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool read_next_line(FILE *source_file, char *line); /*A function that reads the next line in the file*/

/**/
typedef enum {
    ERROR_FILE_READ, 
    ERROR_EMPTY_FILE, 
    ERROR_EOF_REACHED
} ErrorCode;


void handle_error(ErrorCode error_code);/*A function that handles errors while reading a line from a source file*/

/**/
typedef struct Symbol {
    char name[MAX_SYMBOL_LENGTH];
    int value;
    char type;  /* 'c' for code*/
    struct Symbol* next;  /* Pointer to the next symbol in the list*/
} Symbol;

Symbol* symbol_table = NULL;  /* Head of the linked list*/

/*TODO:int IC = 0;   ????????????????????*/
