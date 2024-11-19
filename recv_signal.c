/**
 * File: recv_signal.c
 * Modified by: Jadyn Osborne
 * 
 * Brief summary of program: Uses SIGUSR1 handler to receieve and print
 * information from the othe process that is using sigqueue.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 with data: %d, from PID: %d\n",
           (*info).si_value.sival_int, (*info).si_pid);
}

int main() {

    pid_t pid = getpid(); // getting this programs pid
    // printing pid so user can use it in send_signal command line argument
    printf("The current process ID is: %d\n", pid); 

    struct sigaction sa;
    sa.sa_sigaction = handle_sigusr1;  // register handler in sa_sigaction field
    sa.sa_flags = SA_SIGINFO; // enable additional signal info

    sigaction(SIGUSR1, &sa, NULL);    // registering handler for SIGUSR1

    printf("Waiting for SIGUSR1 with data...\n");
    pause();
    return 0;
}
