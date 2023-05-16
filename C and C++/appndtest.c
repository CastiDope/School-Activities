/* Copy a text filee of integers.
    Written by:
    Date:
*/
#include<stdio.h>
#include <stdlib.h>

int main(void)
{
    //local declarations
    FILE* spAppnd;
    int numIn;
    int closeResult;

    //statements
    printf("This program appends data to a file\n");
    spAppnd = fopen("casti.txt", "a");
    if (!spAppnd)
    {
        printf("Could not open input file\a\n");
        exit (101);
    }// if open fail

     printf("Please enter first number: ");
       while ((scanf("%d", &numIn)) !=EOF)
    {
        fprintf(spAppnd, "%d\n", numIn);
        printf("Enter next number or <EOF>: ");
    }//while

    closeResult = fclose(spAppnd);
    if (closeResult == EOF)
    {
        printf("Could not close output file\a\n");
        exit (201);
    }// if close fail
    
    printf("\nFile append complete\n");
    return 0;
   
}