/*In order to perform the first pass, we used the algorithm in the course booklet.*/
#include <stdio.h>
#include <stdbool.h>

/*In the first step of the algorithm, we were asked to initialize IC and DC*/
/*IC and DC initialization*/

int IC = 0;
int DC = 0;

/*The function first_pass attempts to open a text file specified by the filename parameter for reading.
 If the file opening fails (e.g., the file doesn't exist or there are permission issues), 
it prints an error message and exits the program with an error code.*/

void first_pass(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening source file.\n");
        exit(EXIT_FAILURE);  /* Exit if there's an error opening the file */
    }


/*In the second step, we were asked to read the following line from the source file.*/
/*It is important to note that this operation repeats itself throughout the entire passage of the file, so we used a loop*/

void first_pass(FILE *source_file) {
    char line[MAXIMUM_LINE_LENGTH];
    int line_counter = 0;

    while (true) {
        if (!read_next_line(source_file, line)) {
            if (line_counter == 0) {
                handle_error(ERROR_EMPTY_FILE);
            }
            break;
        }
        line_counter++;

        
    } /*end of while (read_next_line(source_file, line))*/

/*This section will show the errors and the printouts for the errors*/


}/*end of void first_pass(FILE *source_file)*/ 





