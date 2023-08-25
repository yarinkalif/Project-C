#include "globals.h"

/* Skips whitespaces
   gets source file pointer and skips spaces and tabs in the current line in the file */                                                     
void skip_whitespaces (FILE *file_ptr) {

	char current_character = fgetc(file_ptr); /* current character in the line */

	while (current_character != EOF && current_character != '\n' && (current_character == ' ' || current_character == '\t')) {
		fseek(file_ptr ,-1 ,SEEK_CUR);
		current_character = fgetc(file_ptr);
	}
}

/* Skips whitespaces
   gets source file pointer and skips spaces and tabs in the current line in the file */     
int check_line (FILE *file_ptr, int line_counter) {

	char current_character = fgetc(file_ptr); /* current character in the line */
	int character_counter = 0;
	int word_length_counter = 0;
	int big_word = 0;

	while (current_character != EOF && current_character != '\0' && current_character != '\n') {

		if (current_character != ' ' && current_character != '\t') {
			word_length_counter++;
			character_counter++;
			current_character = fgetc(file_ptr); /* current character in the line */
		}

		if (word_length_counter > MAX_LENGTH_LINE) {
			big_word = 1;
		}

		else {
			word_length_counter = 0;			
			character_counter++;
			current_character = fgetc(file_ptr); /* current character in the line */
	}	}
	
	if (big_word == 1) {
		handle_error(ERROR_WORD_LENGTH, line_counter);
	}

	else if (character_counter > MAX_LENGTH_LINE) {
		handle_error(ERROR_LINE_LENGTH, line_counter);
	}

	return character_counter;
}

/* Skips whitespaces
   gets source file pointer and skips spaces and tabs in the current line in the file */ 
int check_word (char *word, int line_counter, int enable_error) {
	
	int i;

	for (i = 0; i <= 15 || i < strlen(symbols); i++) {
	
		if (i <= 3) {

			if (strcmp(word, directive[i]) == 0) {
				return 1;
			}
		}

		if (strcmp(word, opcodeTable[i].name) == 0) {
			return 2;
		}

		if (strcmp(word, symbols[i]) == 0) {
			return 3;
		}
	}

	if (enabel_error == 1) {
		handle_error(ERROR_INVALID_WORD, line_counter);
	}
	
	return 0;
}

/* Returns if the line is empty
   gets source file pointer and skips spaces and tabs in the current line in the file
   if reached to '\n' returns 1 and if not returns 0 */
int check_directive (FILE *file_ptr, char *word, int line_counter, int enable_error) {
	
	skip_whitespaces(file_ptr);
	char current_character = fgetc(file_ptr); /* current character in the line */

	if (strcmp(word, ".data") == 0) {
		
		int number_counter = 0;

		if (current_character == ',') {
			printf("Line %d: Error - comma cannot be before first number\n", line_counter);
			return 0;
		}





	}


}

/* Returns if the line is empty
   gets source file pointer and skips spaces and tabs in the current line in the file
   if reached to '\n' returns 1 and if not returns 0 */
int check_instruction (FILE *file_ptr, char *word, int line_counter, int enable_error) {

	skip_whitespaces(file_ptr);

	if (strcmp(word, ".mov") == 0) {

	}

	else if (strcmp(word, ".cmp") == 0) {

	}

	else if (strcmp(word, ".add") == 0) {

	}

	else if (strcmp(word, ".sub") == 0) {

	}

	else if (strcmp(word, ".not") == 0) {

	}

	else if (strcmp(word, ".clr") == 0) {

	}

	else if (strcmp(word, ".lea") == 0) {

	}

	else if (strcmp(word, ".inc") == 0) {

	}

	else if (strcmp(word, ".dec") == 0) {

	}

	else if (strcmp(word, ".jmp") == 0) {

	}

	else if (strcmp(word, ".bne") == 0) {

	}

	else if (strcmp(word, ".red") == 0) {

	}

	else if (strcmp(word, ".prn") == 0) {

	}

	else if (strcmp(word, ".jsr") == 0) {

	}

	else if (strcmp(word, ".rts") == 0) {

	}

	else if (strcmp(word, ".stop") == 0) {

	}


}

/* Returns if the line is empty
   gets source file pointer and skips spaces and tabs in the current line in the file
   if reached to '\n' returns 1 and if not returns 0 */
int check_symbol (FILE *file_ptr, char *word, int line_counter, int enable_error) {



}

/* Returns if the line is empty
   gets source file pointer and skips spaces and tabs in the current line in the file
   if reached to '\n' returns 1 and if not returns 0 */
int add_symbol (FILE *file_ptr, char *word, int line_counter, int enable_error) {

	int i = 0;

	skip_whitespaces(file_ptr);

	while (i < strlen(symbols)) {
		if (strcmp(word, symbols[i]) == 0 && enable_error == 1) {
			handle_error(ERROR_MULTIPLE_SYMBOLS, line_counter);
			return 0;
		}

		if (strcmp(word, symbols[i]) == 0) {
			return 0;
		}
		
		i++;
	}

	if (strcmp(word[strlen(word)-1], ':') != 0 && enable_error == 1) {
		handle_error(ERROR_NO_COLON_SYMBOL, line_counter);
		return 0;
	}

	else if (strcmp(word[strlen(word)-1], ':') != 0) {
		return 0;
	}


	return 1;
}


/* Returns if the line is empty
   gets source file pointer and skips spaces and tabs in the current line in the file
   if reached to '\n' returns 1 and if not returns 0 */
int empty_line (FILE *file_ptr) {

	skip_whitespaces(file_ptr);

	char current_character = fgetc(file_ptr); /* current character in the line */

	if (current_character == '\n') {
		return 1;
	}

	return 0;
}

/* Returns if reached to end of file
   gets source file pointer and skips spaces and tabs in the current line in the file
   if reached to end of file returns 1 and if not returns 0 */
int end_of_file (FILE *file_ptr) {

	skip_whitespaces(file_ptr);

	char current_character = fgetc(file_ptr); /* current character in the line */

	if (current_character == EOF) {
		return 1;
	}

	return 0;
}

/* Returns if reached to end of file
   gets source file pointer and skips spaces and tabs in the current line in the file
   if reached to end of file returns 1 and if not returns 0 */
char get_word (FILE *file_ptr) {
	
	char current_character = fgetc(file_ptr); /* current character in the line */
	char *word = (char*)malloc(MAX_LENGTH_LINE * sizeof(char));
	int i = 0;

	while (current_character != EOF && current_character != '\0' && current_character != '\t' && current_character != ' ' && current_character != '\n') {

		word[i] = current_character;
        	i++;
		fseek(file_ptr ,-1 ,SEEK_CUR);
		current_character = fgetc(file_ptr);
	}

	word[i] = '\0';
	return word;
}
