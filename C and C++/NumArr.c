#include <stdio.h>
void ascendingSort (int n1, int n2, int n3);
void descendingSort (int n1, int n2, int n3);
int checkhighest (int n1, int n2, int n3);

int main()
{
    int num1, num2, num3;
    int ch, chsort, highest;

    printf("Please input 3 number: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("The highest number is %d," checkhighest(num1, num2 num3));

    printf("Would you like to arrange your numbers?(y/n)");
    scanf("%c", &ch);
    if (ch =='y')
    {
        printf("Arrangement to (a)ascending or (d)descending?: ");
        scanf("%c", &chsort);

        if(chsort== 'a')
        {
            ascendingSort (num1, num2, num3);
        }
        else
        {
            descendingSort (num1, num2, num3);
        }

    }
    else
    {
        printf("You did not arrange the numbers.");
    }
    return 0;
}

int checkhighest (int n1, int n2, int n3)
{
    int highest;

    if(n1 > n2 && n1 > n3);
        n1 = highest;
    else if(n2 > n1 && n2 > n3);
        n2 = highest;
    else (n3 > n1 && n3 > n2);
        n3 = highest;
    return highest;
}

void ascendingSort (int n1, int n2, int n3)
{
    int highest;
    int middle;
    int lowest;

    if(n1 > n2 && n1 > n3)
    {   n1 = highest;
    else if(n2 > n1 && n2 > n3)
        n2 = highest;
    else (n3 > n1 && n3 > n2)
        n3 = highest;
    }
    if(n1 > n2 && n1 < n3)
    {  n1 = middle;
    else if(n2 > n1 && n2 < n3)
        n2 = middle;
    else (n3 > n1 && n3 < n2)
        n3 = middle;
    }
    if(n1 < n2 && n1 < n3)
    {    n1 = lowest;
    else if(n2 < n1 && n2 < n3)
        n2 = lowest;
    else (n3 < n1 && n3 < n2)
        n3 = lowest;    
    }
    printf("\n Ascending order : %d %d %d", &lowest, &middle, &highest);
}

//void descendingSort (int n1, int n2, int n3)
