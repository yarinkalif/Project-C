#ifndef FIRST_PASS_FUNC_H
#define FIRST_PASS_FUNC_H
#include <stdbool.h>
#include "data.h"


bool is_symbol(const char* line);
bool is_data_directive(const char* line);
bool is_extern_or_entry(const char* line);
void handle_symbol_table(const char* line);
void some_function();
bool is_symbol_declaration(const char* line);
bool is_symbol_declaration(const char* line);
void process_line_with_symbol(const char* line);
void process_line_without_symbol(const char* line);
bool read_line_from_source(FILE* fp, char* buffer);
bool add_symbol(const char* name, int type);
void process_line_with_symbol(const char* line);
void process_line_without_symbol(const char* line);
bool read_line_from_source(FILE* fp, char* buffer);
bool is_symbol_declaration(const char* line);
void process_line_with_symbol(const char* line, DataEntry** data_list, int* data_counter);
void process_line_without_symbol(const char* line, DataEntry** data_list, int* data_counter);


#endif

