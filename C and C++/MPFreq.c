#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char ch;
    int count[26] = {0};
    int i;

    fp = fopen("text.txt", "r");
    if (fp == NULL)
    {
        printf("File does not exist or cannot be opened. \n");
        exit(0);

    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            count[ch - 'a']++;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            count[ch - 'A']++;
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            printf("%c occurs %d times in the file. \n", i + 'a', count[i]);
        }
    }

    fclose(fp);
    return 0;
}