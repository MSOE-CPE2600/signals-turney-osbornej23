/**
 * File: send_signal.c
 * Modified by: Jadyn Osborne
 * 
 * Brief summary of program: Uses the sigqueue function to send a SIGUSR1
 * signal to another waiting process (recv_signal.c) along with custom data
 * (a randomly generated integer value)
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {

    // saw some functions use a similar technique
    // typed so that if the runner runs with no arguments they know what
    // arguments are to be expected since nothing happens
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        return 1;
    }
    
    // getting the target pid from the command line
    pid_t target_pid = atoi(argv[1]);  

    srand(time(NULL));
    // random integer generation
    int random_value = rand() % 100;

    union sigval sig_data;
    sig_data.sival_int = random_value;

    printf("Sending SIGUSR1 with data: %d to PID: %d\n", random_value, target_pid);
    if (sigqueue(target_pid, SIGUSR1, sig_data) == -1) {
        perror("sigqueue failed");
        return 1;
    }

    return 0;
}

