

int main() {
    symbol_table.count = 0;

    char* test_field = "MAIN";  /* Example usage*/
    char result = process_field(test_field);
    printf("Result: %c\n", result);

    /* Free memory of the symbol table (should be done at the end of the program)*/
    Symbol* current = symbol_table;
    while (current != NULL) {
        Symbol* next = current->next;
        free(current);
        current = next;
    }

    return 0;

}/*end of main*/


