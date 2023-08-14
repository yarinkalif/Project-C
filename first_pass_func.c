/*This document has been meticulously constructed to encompass the functionalities pertinent to the initial phase,
 thereby fostering a structured and lucid project architecture.*/

#include <stdio.h>
#include <stdbool.h>
#include "data.h"


/*This function reads the following string from the source file.
The function returns "true" if the line was read successfully and "false" if an error occurred or the end of the file was reached.*/




bool read_next_line(FILE *file, char *lineData, int lineDataSize) {
    if (!file || !lineData || lineDataSize <= 0) {
        return false;  /* Invalid parameters.*/
    }

    if (!fgets(lineData, lineDataSize, file)) {
        if (ferror(file)) {
            perror("Error reading from file");
            return false;  /* Error reading from the file.*/
        }
        return false;  /* End of file or empty line.*/
    }

    return true;
}

/* Function to search for a symbol in the table and return its data */
SymbolTable* findSymbolInTable(const char* symbol) {
    for (int i = 0; i < currentSymbolsCount; i++) {
        if (strcmp(symbolTable[i].name, symbol) == 0) {
            return &symbolTable[i];
        }
    }
    return NULL;
}

/* Pointer to the symbol table. */
SymbolTable *symbolTable = NULL;
int currentSymbolsCount = 0; /* Counter to keep track of the number of symbols */

/* Function to add a symbol to the table */
void addSymbolToTable(const char* symbol, int address, SymbolType type) {
    /* Allocate/reallocate memory for the symbol table */
    symbolTable = realloc(symbolTable, (currentSymbolsCount + 1) * sizeof(SymbolTable));
    if (!symbolTable) {
        perror("Failed to allocate memory for symbol table");
        exit(1);
    }
    
    /* Add the new symbol */
    strcpy(symbolTable[currentSymbolsCount].name, symbol);
    symbolTable[currentSymbolsCount].address = address;
    symbolTable[currentSymbolsCount].type = type;
    currentSymbolsCount++;
}

/* Function to insert a data symbol (label) into the symbol table. */
void insertDataSymbol(const char* label) {
    /* Check if the label already exists in the table */
    if (findSymbolInTable(label)) {
        printf("Error: The label %s is already defined in the table.\n", label);
        return;
    }
    /* Add the label to the table with the value of DC */
    addSymbolToTable(label, *DC, DATA_SYMBOL);
}


/* Data structures */
typedef struct {
    char label[31]; /*Maximum label length*/
    int address;
} SymbolTableEntry;





SymbolTableEntry symbolTable[1000];
int symbolTableSize = 0;

/* Process the line */
char label[31] = "";
char directive[31]; *************************************************************
int values[31];
int valuesCount = 0;

sscanf(line, "%[^:]: .%s", label, directive); 

if (label[0] != '\0') {
    strcpy(symbolTable[symbolTableSize].label, label);
    symbolTable[symbolTableSize].address = DC; 
    symbolTable[symbolTableSize].type = 'N'; /* Default type is normal */
}

if (strcmp(directive, "data") == 0) {
    char *valueStr = strtok(line, " ");
    while(valueStr != NULL) {
        valueStr = strtok(NULL, ",");
        if(valueStr) {
            sscanf(valueStr, "%d", &values[valuesCount]);
            valuesCount++;
        }
    }
    DC += valuesCount;
}
else if (strcmp(directive, "string") == 0) {
    char stringValue[1000];
    sscanf(line, ".string %s", stringValue);
    
    /* The length of the string +1 for the null terminator */
    DC += strlen(stringValue) + 1;
}
else if (strcmp(directive, "entry") == 0) {
   sscanf(line, ".entry %s", label);

    int i;
    for(i = 0; i < symbolTableSize; i++) {
        if (strcmp(symbolTable[i].label, label) == 0) {
            symbolTable[i].type = 'E';
            break;
        }
}
    /* if label was not found in the symbol table yet, add it */
    if (i == symbolTableSize) {
        strcpy(symbolTable[symbolTableSize].label, label);
        symbolTable[symbolTableSize].type = 'E';
        symbolTableSize++;
    }
}
else if (strcmp(directive, "extern") == 0) {
    sscanf(line, ".extern %s", label);

    strcpy(symbolTable[symbolTableSize].label, label);
    symbolTable[symbolTableSize].address = 0; /* Extern symbols might not have a meaningful address in the current file. */
    symbolTable[symbolTableSize].type = 'X';
    symbolTableSize++;
}



