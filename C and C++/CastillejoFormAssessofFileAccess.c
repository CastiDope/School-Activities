#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE* humptyCasti;
    int ioResult;
    char story [10];

    humptyCasti = fopen("C:\\Users\\JOMAR\\Desktop\\casti.txt", "r");

    if (humptyCasti)
    {
             ioResult = fscanf(humptyCasti, "%d", &story);
            while (ioResult != -1)
            {
                printf("ioResult: = %d and Words: %s\n", ioResult, story);
                ioResult=fscanf(humptyCasti, "%s", &story);
            }
    }  
    else
    {
        printf("SUCH FILE HAS NO EXISTENCE!");
        exit(100);
    }
    
    printf("ioResult = %d", ioResult);
    fclose(humptyCasti);

    return 0;
}