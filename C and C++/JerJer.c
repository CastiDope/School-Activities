#include <stdio.h>

int main ()
{
    int a,b,c,sum;

    printf("\nWelcome. This program adds\n");
    printf("three numbers. Enter three numbers\n");
    printf("in the form of: nnn nnn nnn <return>\n");
    scanf("%d %d %d, &a, &b, &c");

    sum = a + b + c;

    printf("The total is: %d\n\n, sum");

    printf("Thank you. Have a good day\n");
    return 0;
}
