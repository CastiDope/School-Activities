#include <stdio.h>
#define a 19 //My current age

int main()
{
    int tAge; //total age 
    int x;     //year passed

    printf("Enter an integer");
    scanf("%d", &x);

    tAge = a + x; //year passed added to current age
    printf("Integer = %d \n", x);
    printf("total = %d \n", tAge);
    return 0;
}
