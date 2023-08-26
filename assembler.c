#include <stdio.h>
#include <stdlib.h>
#include "assembler.h"
#include "first_pass.h"
#include "table.h"
#include "errors.h"

/* 
 * The main function responsible for processing assembly files.
 * @param argc: The count of command-line arguments.
 * @param argv: An array of command-line arguments.
 * @return: Returns 0 if file processing failed, else the result of assembly_to_machine_code function.
 */

int main(int argc, char *argv[])
{
	int fileSuccess = 0, i;
	
	/* Check if no file is provided in the input */
	if (argc == 1) 
	{
		printf("ERROR: Please enter assembly file name");
		exit(EXIT_SUCCESS); 
	}

	/* Process each file provided in the input */
	for(i = 1; i < argc; i++)
	{
		fileSuccess = assembly_to_machine_code(argv[i]);
		if(fileSuccess == 0)
		{
			printf("\n '%s' The file has failed.\n", argv[i]);
		}
	}	

	return fileSuccess;
}

/* 
 * Converts the provided assembly file to machine code.
 * @param fileName: The name of the file to be processed.
 * @return: Returns 1 if the process was successful, 0 otherwise.
 */
int assembly_to_machine_code(char* fileName)
{	
	long ic = 0, dc = 0; 
	int success = 0, line_number = 0;
	char *currLine = (char*)calloc(MAX_LENGTH_LINE + 2, sizeof(char));
	char *amFileName = (char*)malloc(256 * sizeof(char));
	FILE *file_desc;
	s_table *symbolTable = NULL;

	/* Preprocess the file */
	success = preassembler_file(fileName);
	if (success != 1) 
	{
		printf("Couldn't spread the macros correctly into %s.as\n", fileName);
	}
	
	amFileName = filename_suffix(fileName, ".am");
	file_desc = fopen(amFileName, "r");
	if (file_desc == NULL) 
	{
		printf("Couldn't open the file %s.\n", ".am");
		free(amFileName);
		return 0;
	}

	/* First pass: Read each line from the file and process it */
	symbolTable = create_symbol_table(); /* Create a table to store symbols */

	while (fgets(currLine, MAX_LENGTH_LINE + 2, file_desc) != NULL) 
	{ 
		if (strchr(currLine, '\n') == NULL && !feof(file_desc)) 
		{
			handle_error(ERROR_LINE_LENGTH, line_number); /* Handle case where line length is too long */
			success = 0;
		}
		if (!currLine) 
		{
			handle_error(ERROR_MEMORY_ALLOCATION, line_number);
		}
		else 
		{
			printf("The line is: %s\n", currLine);
			success = first_pass(file_desc, currLine, symbolTable, &ic, &dc, line_number);
		}
		line_number++;
	}
	
	/* Second pass (not yet implemented) */ ************************************************************************************************************************
	/*rewind(file_desc);*/
			
	free(amFileName);	
	
	return success;
}

