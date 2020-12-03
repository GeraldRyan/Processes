// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    int f = fork();

    if (f == 0)
    {
        x++;
        printf("Hello world from child\n");
        printf("Value of X (Child) is %i\n", x);
    }
    else{
        x--;
        printf("Hello world from parent. Child ID is %d\n", f);
        printf("Value of X (Parent) is %i\n", x);

    }
    return 0;
}
