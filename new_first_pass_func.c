#include <stdio.h>
#include <stdbool.h>
#include "data.h"
#include "first_pass_func.h"
#include <ctype.h> 



bool is_symbol(const char* line) {
    /* Your implementation here*/
    return false; // placeholder
}

void handle_symbol_table(const char* line) {
    /* Your implementation here*/
}

bool is_data_directive(const char* line) {
    /* Your implementation here*/
    return false; /* placeholder*/
}

bool is_extern_or_entry(const char* line) {
    /* Your implementation here*/
    return false; /* placeholder*/
}



bool is_symbol_declaration(const char* line) {
    /* Find the position of the colon*/
    const char* colon_pos = strchr(line, ':');
    if (colon_pos == NULL) {
        return false; /* No colon found*/
    }

    /* Make sure there's no space between the label and the colon*/
    if (colon_pos > line && isspace(*(colon_pos - 1))) {
        return false; /* Space before colon*/
    }

    /* Extract potential label name*/
    const char* start_label = line;
    while (start_label < colon_pos && isspace(*start_label)) {
        start_label++; /* Skip leading spaces*/
    }

    /* Check if the label name is valid*/
    const char* curr = start_label;
    if (!isalpha(*curr)) { /* First char must be alphabetic*/
        return false;
    }
    curr++;

    int label_length = 1; /* We already checked the first character*/
    while (curr < colon_pos && (isalpha(*curr) || isdigit(*curr)) && label_length <= 31) {
        curr++;
        label_length++;
    }

    /* Check if we reached the colon and did not exceed the label length*/
    return (curr == colon_pos) && (label_length <= 31);
}

bool add_symbol(const char* name, int type) {
    /* First, check if symbol already exists*/
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            /* Symbol already exists, return an error (false)*/
            return false;
        }
    }

    /* Add the symbol to the table*/
    strncpy(symbol_table[symbol_count].name, name, sizeof(symbol_table[symbol_count].name));
    symbol_table[symbol_count].type = type;
    if (type == DATA) {
        symbol_table[symbol_count].value = DC;
    } 
    /* Else, if other types of symbols are added, their values should be assigned appropriately here*/

    symbol_count++;
    return true;
}

void process_line_with_symbol(const char* line) {
    char symbol[32];
    sscanf(line, "%31[^:]", symbol);
    
    /* Add symbol to the symbol table. If it's a data symbol, the value will be DC.*/
    if (!add_symbol(symbol, DATA)) {
        /* Handle error: Symbol already exists in the table.*/
        fprintf(stderr, "Error: Symbol %s already exists.\n", symbol);
    }
}

void process_line_without_symbol(const char* line) {
    /* Continue processing the instruction based on your assembly language definition.*/
    /* This might include increasing the DC if it's a data instruction, etc.*/
}
