#include "data.h"
#include "first_pass_func.h"
#include "first_pass.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {
    char* filename = "source.txt"; /* */ 
    first_pass(filename);
/* MY CODE  */ 

    return 0;



bool read_line_from_source(FILE* fp, char* buffer) {
    if (fgets(buffer, LINE_BUFFER_SIZE, fp) != NULL) {
        return true;
    }
    return false;
}

    FILE* fp = fopen("source.asm", "r");
    char line_buffer[LINE_BUFFER_SIZE];

    if (!fp) {
        perror("Failed to open source.asm");
        return 1;
    }

    while (read_line_from_source(fp, line_buffer)) {
        if (is_symbol_declaration(line_buffer)) {
            process_line_with_symbol(line_buffer);
        } else {
            process_line_without_symbol(line_buffer);
        }
    }

    fclose(fp);
    return 0;

    FILE* fp = fopen("source.asm", "r");
    char line_buffer[MAX_INSTRUCTION_SIZE];
    DataEntry* data_list = NULL;
    int data_counter = 0;

    if (!fp) {
        perror("Failed to open source.asm");
        return 1;
    }

    while (read_line_from_source(fp, line_buffer)) {
        if (is_symbol_declaration(line_buffer)) {
            process_line_with_symbol(line_buffer, &data_list, &data_counter);
        } else {
            process_line_without_symbol(line_buffer, &data_list, &data_counter);
        }
    }

    fclose(fp);
    return 0;


} /*end of maim*/
