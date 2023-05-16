#include <stdio.h>

int main()

{
    int a,b,c;
    int *x,*q,*p,**y,**r,***z;

    x=&a;
    p=&b;
    y=&p;
    q=&c;
    r=&q;
    z=&r;

    printf("Input a value for variable a: ");
    scanf("%d",x);
    printf("input a value for variable b: ");
    scanf("%d",*y);
    c = (**y) * (*x);

    printf("The value of variable a using the pointer x: %d\n",*x);
    printf("The value of variable b using the pointer y: %d\n",**y);
    printf("The value of variable c using the pointer z: %d\n",***z);

    return 0;
}