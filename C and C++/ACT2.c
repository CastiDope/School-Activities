#include<stdio.h>

void main()
{
    int x;

    printf("Enter a number:");
    scanf("%d", &x);

    if(x > 0){
        printf("%d is a positive number.", x);
    } else if(x < 0){
        printf("%d is a negative number.", x);
    } else if(x == 0){
        printf("%d is equal to zero.", x);
    }
}