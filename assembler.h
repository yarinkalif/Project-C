#ifndef MAIN_H
#define MAIN_H

/* 
 * Header file for the main functionality of the assembly-to-machine code conversion.
 */

/* Libraries and headers for various functionalities required in the main conversion process:*/

/* Include preassembler functions and structures */
#include "preassembler.h"

/* Include symbol table functions and structures */
#include "table.h"

/* Include global constants and variables */
#include "globals.h"

/* Include utility functions for general-purpose operations */
#include "utils.h"

/* Include error handling functions and constants */
#include "errors.h"

/* 
 * Converts the provided assembly file to machine code.
 * @param fileName: The name of the file to be processed.
 * @return: Returns 1 if the process was successful, 0 otherwise.
 */
int assembly_to_machine_code(char* fileName);

#endif

