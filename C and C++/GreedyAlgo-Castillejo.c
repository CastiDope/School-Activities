#include<stdio.h>
#define max 100

//arr - will have list of needed currencies
int ans[max];

int findMinCoins(int currencies[], int size,  int value);

int main()
{
    int currencies[] = {25,20,10,5};
    int value = 230, i;

    //find the size of the currency array
    int size = sizeof(currencies)/sizeof(currencies[0]);

    int MinCount = findMinCoins(currencies,size,value);

    printf("Total Currencies Needed = %d\n",MinCount);

    printf("Currencies are:\t");
    for(i = 0; i < MinCount; i++)
        printf("%d ", ans[i]);

    return 0;
}

int findMinCoins(int currencies[], int size,  int value)
{
    int i, count = 0;

    for(i = 0; i < size; i++)
    {
        //taking as much from currencies[i]
        while(value >= currencies[i])
        {
            //after taking the currency, reduce the value.
            value -= currencies[i];
            ans[count] = currencies[i];
            count++;
        }
        if(value == 0)
            break;

    }

    return count;
}

