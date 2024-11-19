/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Jadyn Osborne
 * 
 * Brief summary of modifications: Added a signal handler for SIGSEGV
 */


#include <stdio.h>
#include <signal.h>

/**
 * @brief Signal handler for SIGSEGV - prints a message and exits
 */
void handle_signal() {
    printf("Received a segmentation fault violation signal\n");
    // This does not gracefully terminate the program, because of this, the
    // program will continuously go back and rerun the line of code that
    // caused the seg fault signal and repeatedly call this handler.
    // In this case the sigfault causing code is the dereferencing of a null
    // pointer in main.
}

int main (int argc, char* argv[]) {
    // Register for the signal
    signal(SIGSEGV, handle_signal);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}