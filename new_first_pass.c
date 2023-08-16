#include "data.h"
#include "data.h"
#include "first_pass_func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*IC and DC initialization*/
int IC = 0;
int DC = 0;

void first_pass(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening source file.\n");
        exit(EXIT_FAILURE);  /* Exit if there's an error opening the file */
    }

    char line_buffer[82]; /* Buffer to hold the current line from the source file */
    while (read_line_from_source(fp, line_buffer)) {
        /* Handle the line based on the checks */
        if (is_symbol(line_buffer)) {
            /* Handle symbols*/
            handle_symbol_table(line_buffer);
        } else if (is_data_directive(line_buffer)) {
            /* Handle data directives*/
            /* TODO: Add the relevant function or handling code here*/
        } else if (is_extern_or_entry(line_buffer)) {
            /* Handle .extern or .entry*/
            /* TODO: Add the relevant function or handling code here*/
        }

        printf("%s", line_buffer); 

    bool symbol_flag = false;

    if (is_symbol_declaration(line_buffer)) {
        symbol_flag = true;
    }

void process_line_with_symbol(const char* line) {
    /* Here you will implement the logic for handling rows that have a label */
}

void process_line_without_symbol(const char* line) {
    /* Here you will implement the logic for handling rows that do not have a label*/
}
    
}


    }

    fclose(fp);
    /* Check for errors here. If there are errors, terminate the program. */
}
