/*
Write a program that will find the average time it takes for your computer
to make a system call an empty write to stdout. Your program should use the 
`clock_gettime` procedure to time how long a single system call takes. It'll 
do this for one million iterations, and then find the average of all of those 
iterations in nanoseconds.
For some helpful documentation and examples of using time-related system calls,
visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
While the linked site does say that `clock_gettime()` does not work on OSX, this 
turns out to only be the case for OSX versions < 10.12. Anything later than that 
and `clock_gettime()` should work just fine. 
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define number_iter 10000
#define BILLION 1000000000L

int main()
{
    // Your code here
    long start_t, end_t, total_t, avg_t;
    struct timespec start, end;
    start_t = clock();
    // clock_gettime(CLOCK_REALTIME)
    for (int i = 0; i < number_iter; i++)
    {
        fprintf(stdout, ""); // empty write to standard out (equivalent to printf(""))
    }
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    avg_t = total_t/number_iter;
    printf("Total Time and Average time taken by CPU for system call is %f and %lf\n", total_t, avg_t);
    return 0;
}
