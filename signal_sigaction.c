/**
 * File: signal_sigaction.c
 * Modified by: Jadyn Osborne
 * 
 * Brief summary of program: Uses sigaction to register a handler for
 * SIGUSR1, then waits until the SIGUSR1 signal is received and 
 * prints the pid of the sender
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/**
 * @brief Signal handler for SIGUSR1 - prints PID of sender
 */
void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    // printing out the process id of the sender
    printf("Received SIGUSR1 from PID: %d\n", (*info).si_pid);
}

int main() {
    // declaring the sigaction struct
    struct sigaction sa;

    // attaching the handler to sigaction
    sa.sa_sigaction = handle_sigusr1;
    // enable additional signal information
    sa.sa_flags = SA_SIGINFO;

    // registering signal handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction failed");
        exit(1);
    }

    printf("Waiting for SIGUSR1. Send the signal using the command:\n");
    printf("kill -SIGUSR1 %d\n", getpid());  // Print the PID for sending the signal

    pause();

    return 0;
}