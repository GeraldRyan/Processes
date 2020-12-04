// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    // FILE *file;
    // int c;
    // file = fopen("./text.txt", "r");
    // while(1){
    //     c = fgetc(file); // next character in stream
    //     if (feof(file)){
    //         printf("\nEnd of file reached\n");
    //         printf("\n%i\n", feof(file));
    //         break;
    //     }
    //     printf("%c", c);
    //     printf("Closing File\n");
    //     fclose(file);
    // }
    FILE *file;
    file = fopen("./text.txt", "w");
    fork();
    fprintf(file, "When in the course of human events\n");
    fclose(file);

    return 0;
}
