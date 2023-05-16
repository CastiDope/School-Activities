#include <stdio.h>

int main(void)

{
    int a, b, s, m, d, r;
    int* pa = &a; 
    int* pb = &b;
    int* ps = &s;
    int* pm = &m;
    int* pd = &d;
    int* pr = &r;

    printf("Enter the first number: ");
    scanf("%d",pa);
    printf("Enter the second number: ");
    scanf("%d",pb);
    *ps=*pa-*pb;
    printf("\nSubtraction of %d and %d is = %d",*pa,*pb,*ps);
    *pm=*pa * *pb;
    printf("\nMultiplication of %d and %d is = %d",*pa,*pb,*pm);
    *pd=*pa / *pb;
    printf("\nDivision of %d and %d is = %d",*pa,*pb,*pd);
    *pr=*pa % *pb;
    printf("\nRemainder of %d and %d is = %d",*pa,*pb,*pr);

    return 0;
}