/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Jadyn Osborne
 * 
 * Brief summary of modifications: Replaced exit() with a self terminating
 * kill function. There is an exit in case of unique error, but first it
 * will attempt to exit via a signal kill as requested by lab. Another way
 * of entering the handler and exiting is by pressing CTRL+C as the user,
 * and this will send a signal interrupt to the system and enter its handler.
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    // will end process via sigkill and not exit unless unique circumstance
    if (kill(getpid(), SIGKILL) == -1) {
        perror("Error: Failed to self terminate");
        exit(1);
    }
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}