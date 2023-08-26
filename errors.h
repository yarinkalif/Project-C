#ifndef ERRORS_H
#define ERRORS_H

#include "globals.h"

/**
 * @file errors.h
 * This header file contains definitions and declarations related to error handling.
 */
/**
 * @brief Handles error messages associated with reading and processing a source file.
 * 
 * This function takes an error code and the line number where the error occurred. Based on the given error code, 
 * it prints a relevant error message, indicating the exact line in the source file that caused the error.
 * 
 * @param error_code    The error code corresponding to the detected error. Error codes are defined in "globals.h".
 * @param line_counter  The line number in the source file where the error was detected.
 */
void handle_error(int error_code, int line_counter);

#endif 

