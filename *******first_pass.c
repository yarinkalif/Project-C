/*In order to perform the first pass, we used the algorithm in the course booklet.*/
#include <stdio.h>
#include <stdbool.h>
#include "firs_pass_func.h"
#include <stdlib.h>
#include <string.h>


/*In the first step of the algorithm, we were asked to initialize IC and DC*/
/*IC and DC initialization*/

int IC = 0;
int DC = 0;

/*The function first_pass attempts to open a text file specified by the filename parameter for reading.
 If the file opening fails (e.g., the file doesn't exist or there are permission issues), 
it prints an error message and exits the program with an error code.*/

void first_pass(char* filename) {
    FILE* source_file = fopen(filename, "r");
    if (source_file == NULL) {
        printf("Error opening source file.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAXIMUM_LINE_LENGTH];
    int line_counter = 0;

*In the second step, we were asked to read the following line from the source file.*/
/*It is important to note that this operation repeats itself throughout the entire passage of the file, so we used a loop*/

    while (read_next_line(source_file, line)) {
        line_counter++;

        /* Removing leading and trailing whitespaces (if there are any)*/
        char *field = strtok(line, " \t\n");
        if (field == NULL) continue; // Empty or whitespace-only line, skip processing.

        char instruction_type = process_field(field);

        /* Handling symbols*/
        if (instruction_type == 's') {
            if (symbol_exists(field)) {
                printf("Error: Symbol %s already exists in the symbol table.\n", field);
            } else {
                insert_symbol(field, DC, SYMBOL_TYPE_DATA);
                /* Continue processing the line to check for directives or commands following the symbol.*/
                field = strtok(NULL, " \t\n");
                instruction_type = process_field(field);
            }
        }

        if (instruction_type == 'e') {
            /* Handling .extern and .entry directives*/
            handle_instruction(field, strtok(NULL, ""));
        } else if (instruction_type == 'd') {
            /* Handle data (.data or .string) here if needed.*/
            /* Code for processing data directives can be added here.*/
        } else if (instruction_type == 'u') {
            /* Handle commands or unknown fields here.*/
            /* Code for processing commands or handling errors for unknown fields can be added here.*/
        }
    }

    if (line_counter == 0) {
        handle_error(ERROR_EMPTY_FILE);
    }

    fclose(source_file);
 }/*end of  while (read_next_line(source_file, line))*/
}/*end of void first_pass(FILE *source_file)*/ 
