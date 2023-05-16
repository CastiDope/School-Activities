#include <stdio.h> 

int main() 
{   
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Roman numerals: ");        

    while(num != 0)
    {

        if (num >= 1000)       // 1000 - M
        {
           printf("M");
           num -= 1000;
        }

        else if (num >= 900)   // 900 -  CM
        {
           printf("CM");
           num -= 900;
        }        

        else if (num >= 500)   // 500 - D
        {           
           printf("D");
           num -= 500;
        }

        else if (num >= 400)   // 400 -  CD
        {
           printf("CD");
           num -= 400;
        }

        else if (num >= 100)   // 100 - C
        {
           printf("C");
           num -= 100;                       
        }

        else if (num >= 90)    // 90 - XC
        {
           printf("XC");
           num -= 90;                                              
        }

        else if (num >= 50)    // 50 - L
        {
           printf("L");
           num -= 50;                                                                     
        }

        else if (num >= 40)    // 40 - XL
        {
           printf("XL");           
           num -= 40;
        }

        else if (num >= 10)    // 10 - X
        {
           printf("X");
           num -= 10;           
        }

        else if (num >= 9)     // 9 - IX
        {
           printf("IX");
           num -= 9;                         
        }

        else if (num >= 5)     // 5 - V
        {
           printf("V");
           num -= 5;                                     
        }

        else if (num >= 4)     // 4 - IV
        {
           printf("IV");
           num -= 4;                                                            
        }

        else if (num >= 1)     // 1 - I
        {
           printf("I");
           num -= 1;                                                                                   
        }

    }

    return 0;
} 
