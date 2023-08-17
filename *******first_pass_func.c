#include "first_pass_func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*A function that reads the next line in the file*/
bool read_next_line(FILE *source_file, char *line) {
    if (!fgets(line, MAXIMUM_LINE_LENGTH, source_file)) {
        if (ferror(source_file)) {
            handle_error(ERROR_FILE_READ);
            return false;
        } else if (feof(source_file)) {
            handle_error(ERROR_EOF_REACHED);
            return false;
        }
    }
    return true;  /* Line read successfully */
    }
}

/*A function that handles errors while reading a line from a source file*/
void handle_error(ErrorCode error_code) {
    switch (error_code) {
        case ERROR_FILE_READ:
            printf("Error - the source file is incorrect\n");
            break;
        case ERROR_EMPTY_FILE:
            printf("Error - The file is empty\n");
            break;
        case ERROR_EOF_REACHED:
            printf("Out of source file\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }
}


/*The function takes a symbol name, a numeric value, and a type. It adds the symbol to the global symbol table within the program.
 If the symbol already exists in the table, the program may return an error (if you were to run the method one after the other on the same symbol name).*/
void insert_symbol(char* symbol_name, int value, char type) {
    for (int i = 0; i < symbol_table.count; i++) {
        if (strcmp(symbol_table.symbols[i].name, symbol_name) == 0) {
            printf("Error: Symbol %s already exists!\n", symbol_name);
            exit(1);
        }
    }

    strcpy(symbol_table.symbols[symbol_table.count].name, symbol_name);
    symbol_table.symbols[symbol_table.count].value = value;
    symbol_table.symbols[symbol_table.count].type = type;
    symbol_table.count++;
}


/*The function receives a string and decides what type the field is - whether it is a symbol, a prompt or something else.
 It performs operations based on the type and returns a character that represents the type of the field*/
char process_field(char* field) {
    if (is_symbol(field)) {
        insert_symbol(field, IC, 'c');
        return 's';  /* symbol*/
    } else if (strcmp(field, ".data") == 0 || strcmp(field, ".string") == 0) {
        return 'd';  /* data_instruction*/
    } else if (strcmp(field, ".extern") == 0 || strcmp(field, ".entry") == 0) {
        return 'e';  /* external_entry_instruction */
    } else {
        return 'u';  /* unknown*/
    }
}

/*The function checks whether the string passed to it is a symbol. It returns 1 (true) if the string is a symbol, and 0 (false) otherwise.*/
int is_symbol(char* field) {
    return ((field[0] >= 'A' && field[0] <= 'Z') || (field[0] >= 'a' && field[0] <= 'z')) && is_alphanumeric(field);
}

/*The function checks whether all the characters in the string passed to it are alphanumeric (letters or numbers).
 It returns 1 (true) if all characters are alphanumeric, and 0 (false) otherwise.*/
int is_alphanumeric(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))) {
            return 0;
        }
    }
    return 1;
}

/*The following function checks if the symbol already exists in the table.*/
int symbol_exists(char* symbol_name) {
    Symbol* current = symbol_table;
    while (current != NULL) {
        if (strcmp(current->name, symbol_name) == 0) {
            return 1;  /* true - symbol exists */
        }
        current = current->next;
    }
    return 0;  /* false - symbol doesn't exist */
}

/*The following function creates a limit on the address in memory*/
void ensure_address_in_bounds(int address) {
    if (address < 0 || address >= MEMORY_SIZE) {
        handle_error("Address out of bounds");
    }
}


/*The following function takes care of putting data into memory*/
void memory_insert(int address, unsigned int value) {
    ensure_address_in_bounds(address);
    
/*Check that the value is not too big for memory*/	
    if (value >= (1 << WORD_SIZE)) {
        handle_error("Value too large for memory word");
    }
    memory[address] = value;
}

/*The following function delimits the size of the data that goes into memory*/
void ensure_data_in_bounds(int data) {
    if (data < -(1 << (WORD_SIZE - 1)) || data >= (1 << (WORD_SIZE - 1))) {
        handle_error("Data out of bounds for word size");
    }
}

/*The following function is a function for inserting a whole data (even a third) into memory using the 2's complement method*/
void memory_insert_int(int address, int data) {
    ensure_data_in_bounds(data);
    ensure_address_in_bounds(address);

    if (data < 0) {
        memory[address] = (1 << WORD_SIZE) + data; /*Converting to 2's complement*/
    } else {
        memory[address] = data;
    }
}

/*function to insert a character into memory (when the character is ASCII)*/
void memory_insert_char(int address, char ch) {
    ensure_address_in_bounds(address);
    memory[address] = ch;
}


/*As we mentioned above, we used the algorithm in the course booklet.
 The following function provides an answer to the ninth step and checks whether it is an .extern directive*/
void handle_instruction(char* field, char* operands) {
    char instruction_type = process_field(field);

    /* If the directive is ".extern" */
    if (instruction_type == 'e') {
        char* token = strtok(operands, " \t,");
        while (token != NULL) {
            /* Add the symbol to the symbol table */
            insert_symbol(token, 0, 'E');
            token = strtok(NULL, " \t,");
        }
    }
    /*TODO: Additional checks for other types of instructions can be added here if needed*/
}

