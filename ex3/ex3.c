// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int ecode;
    // Your code here
    pid_t cpid;
    int f = fork();
    cpid = wait(&ecode);
    if (f > 0)
    { // runs code that is for parent only
        printf("I am the parent\n");
    }
    else if (f == 0)
    { // runs code that is for child only // this will always run first since wait is called..i think
        printf("I am the child\n");
        return 100; // ints are between 0 and 255
    }
    // else {
    //     cpid = wait(NULL);
    // }
    printf("Parent PID = %d\n", getpid());
    printf("Child PID = %d\n", cpid);
    printf("this is what child ended with %d\n", ecode);

    if (WIFEXITED(ecode))
        printf("Exit status: %d\n", WEXITSTATUS(ecode));

    return 0;
}
