#include <stdio.h>
#include <ctype.h>

int main()
{
    int num1, num2, num3
    char ch

    printf("Please input 3 number: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("Would you like to arrange your numbers?(y/n)");
    scanf("%c", &ch);
    if (ch =='y')
    return 0;
}
