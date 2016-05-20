//
//  test01.cpp
//  
//
//  Created by Michal Sefcik on 20/05/16.
//
//

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// spawn a child process
int spawn (char* program, char** arg_list) {
    pid_t child_pid;
    
    child_pid = fork();
    if(child_pid != 0) {
        return child_pid;
    } else {
        execvp (program, arg_list);
        fprintf (stderr, "an error occured in execvp\n");
        abort();
    }
}

int main() {
    char* arg_list[] = {
        "time",
        "./test01",
        "1e9",
        NULL
    };
    int nproc=4;
    pid_t child_pid[nproc], wpid;
    for(int i=0; i<nproc; i++) {
        child_pid[i] = spawn ("time", arg_list);
    }
    int child_status;
    while ((wpid = wait(&child_status)) > 0) {
        printf("Exit status of %d was %d\n",(int)wpid,child_status);
    }
    return 0;
}
