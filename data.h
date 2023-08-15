/**/
#define MAX_LINE 1024
#define SYMBOL_NAME_MAX_LENGTH 31 /* Define the maximum length for a symbol's name */



/*Lists of instructions and directives*/
const char instruction[16][6] = {"mov", "cmp", "add", "sub", "not", "clr", "lea", "inc","jmp","bne","dec", "red","prn", "jsr", "rts", "stop"}; 
const char directive[4][7] = {".data", ".string" , ".entry" , ".extern"}';


/* Enum for different types of symbols */
typedef enum {
    CODE_SYMBOL,
    DATA_SYMBOL,
    EXTERNAL_SYMBOL,
    ENTRY_SYMBOL
} SymbolType;

/* Struct to represent each symbol in the symbol table */
typedef struct {
    char name[SYMBOL_NAME_MAX_LENGTH + 1];
    int address;
    SymbolType type;
} SymbolTable;


/*for setting the flag in the third step of the algorithm */
extern int symbolDefinitionFlag;
int symbolDefinitionFlag = 0;

