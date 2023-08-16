#define MAXIMUM_MEMORY_SIZE 1024
#define MAXIMUM_LINE_LENGTH 80
#define MAXIMUM_LABEL_LENGTH 31
#define MAX_SYMBOL_LENGTH 31



/*Lists of instructions and directives*/
const char instruction[16][6] = {"mov", "cmp", "add", "sub", "not", "clr", "lea", "inc","jmp","bne","dec", "red","prn", "jsr", "rts", "stop"}; 
const char directive[4][7] = {".data", ".string" , ".entry" , ".extern"};


/*In the fourth step of the algorithm from the course book, we were asked to turn on a flag: "There is a symbol definition". We need to set the flag first.*/
int flag_symbol_defined = 0;
if (is_symbol(current_field)) {  
    flag_symbol_defined = 1;  /* Set the flag to true*/
    /*TODO:********************************************** rest of the symbol processing logic *********************************************/
}
flag_symbol_defined = 0;
