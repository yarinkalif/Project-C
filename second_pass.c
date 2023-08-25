/*This file is the second pass of our assembler project.*/
/*This assembler, in its second iteration, meticulously reviews the entirety of the source document,
 refining the machine code pertaining to operands which utilize symbols by harnessing the values derived from the symbol table.
 Upon the culmination of this secondary phase, the software will be wholly transmuted into its machine code representation*/
/*In order to build the second transition, we used the algorithm in the course booklet.*/

#include "globals.h"

void second_pass(FILE *file_ptr, char* filename) {
	
    	char current_line[MAX_LENGTH_LINE_PTR]; /* current line in file */
	char current_character; /* current character in line */
	char *current_word; /* current word in the line */
    	int line_counter = 1; /* counts the lines */
	int character_counter = 1; /* counts the characters */
	int result;
	int create_entry_file = 0;
	int create_extern_file = 0;
	IC = 0; /* instruction counter */


	while (end_of_file(file_ptr) == 0 && 1) { /* skips whitespaces and checks the file */

		current_character = fgetc(file_ptr); /* gets the current character in line */

		if (current_character == ';') { /* checks if the line is a comment line */
			fgets(current_line, MAX_LENGTH_LINE_PTR, file_ptr);
			line_counter++;
		}

		if (current_character == '\n') { /* checks if reached to next line */
			line_counter++;
		}

		fseek(file_ptr,-1,SEEK_CUR);
		fgets(current_line, MAX_LENGTH_LINE_PTR, file_ptr);

		current_word = get_word(file_ptr);

		switch (check_word(current_word, line_counter, 0)) {
			case 1:
				result = 1;
				break;
			case 2:
				result = 2;
				break;
			case 3:
				result = 3;
				break;
			default:
				break;
		}

		if (result == 1 || result == 2) {

			skip_whitespaces(file_ptr);

			if (strcmp(current_word, ".entry") == 0) {
				current_word = get_word(file_ptr);

				while (i < strlen(symbols_entry)) {
					if (strcmp(current_word, symbols_entry[i]) == 0) {
						create_entry_file = 1;
						break;
					}

					if (create_entry_file != 1) {
						handle_error(ERROR_UNDECLEARED_ENTRY, line_counter);
					}
				}
			}

			else if (strcmp(word, ".extern") == 0) {
				current_word = get_word(file_ptr);

					while (i < strlen(symbols_extern)) {
						if (strcmp(current_word, symbols_extern[i]) == 0) {
							create_extern_file = 1;
							break;
						}
					}

					if (create_extern_file != 1) {
						handle_error(ERROR_UNDECLEARED_EXTERN, line_counter);
					}
			}

			else if (strcmp(word, ".mov") == 0) {

			}

			else if (strcmp(word, ".cmp") == 0) {

			}



		}
/*
המשך..................................................
*/

    	}

	free(word);

    fclose(source_file);
}
