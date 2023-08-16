#ifndef DATA_H
#define DATA_H
#define LINE_SIZE 80
#define MAX_LINE 1024
#define SYMBOL_NAME_MAX_LENGTH 31 /* Define the maximum length for a symbol's name */

/*Lists of instructions and directives*/
const char instruction[16][6] = {"mov", "cmp", "add", "sub", "not", "clr", "lea", "inc","jmp","bne","dec", "red","prn", "jsr", "rts", "stop"}; 
const char directive[4][7] = {".data", ".string" , ".entry" , ".extern"};

/* Symbol structure */
typedef struct {
    char name[SYMBOL_NAME_MAX_LENGTH + 1];
    int address;
    enum {CODE, DATA} type;
} Symbol;

typedef struct {
    char name[SYMBOL_NAME_MAX_LENGTH + 1]; // Assuming max symbol size is 31 + null-terminator
    int value;
    enum { DATA, OTHER } type; // You can expand this enum if there are more types
} Symbol;

// Define an array for the symbol table. The size can be adjusted as needed.
Symbol symbol_table[LINE_SIZE];
int DC = 0; // This will keep track of the data counter
int symbol_count = 0; // To keep track of how many symbols we've added to the table

// Define a data structure for data entries
typedef struct DataEntry {
    int address;
    int value;
    struct DataEntry* next;
}  DataEntry;



#endif
