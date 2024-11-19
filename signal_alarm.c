/**
 * File: signal_alarm.c
 * Modified by: Jadyn Osborne
 * 
 * Brief summary of program: Triggers an alarm function and sends the resulting
 * SIGALRM after five seconds to a handler which prints a statement
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/**
 * @brief Signal handler for SIGSEGV - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal alarm (SIGALRM)\n");
}

int main (int argc, char* argv[]) {
    // Register for the signal
    signal(SIGALRM, handle_signal);

    // trigger an alarm signal after five seconds
    alarm(5);

    // wait until the signal alarm is received to exit the program
    pause();
    
    return 0;
}
