

int first_pass(FILE *asFile, char *currLine, SymbolTable *symbolTable, long *IC, long *DC, int lineNumber);

int line_data_image(data_image_ptr *currLinePtr, data_image_ptr *tailPtr, char *currLine, int typeOfSentence, long address, char *keyWord, char *operands, int numberLine, SymbolTable *symbolTable);

/*int line_data_image(char *currLine, SymbolTable *symbolTable, int typeOfSentence, int numberLine, long *ic, long *dc);*/

#endif
