#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define MAX 50

int i,a,b,c,item=5,scorep=0,scorem=0,scored=0,scoret=0;
float ave;
char name[31];

void gotoxy(int x,int y);
void add();
void minus();
void multi();
void divi();
int menu();

int main(){
init();
retrieve();
while (1){//infinite loop -> always true
   switch(menu()){
   case 1 : system("cls");system("cls");gotoxy(50,10);printf("Input name : ");scanf(" %s",name);add();break;
   case 2 : system("cls");system("cls");gotoxy(50,10);printf("Input name : ");scanf(" %s",name);minus();break;
   case 3 : system("cls");system("cls");gotoxy(50,10);printf("Input name : ");scanf(" %s",name);divi();break;
   case 4 : system("cls");system("cls");gotoxy(50,10);printf("Input name : ");scanf(" %s",name);multi();break;
   case 5 : exit(0);
   default: printf("Only 1-5!!!\n");system("pause");
        }
    }
}

void add ()
{
    for (i=0;i<item;i++){
        a = rand() % 20 + 1;
        b = rand() % 20 + 1;
    printf("%d.) %s, what is %d + %d = ? ", i+1,name,a,b);scanf("%d",&c);
    if (c == a + b){
    printf("Correct!\n");scorep++;system("pause");
        }
        else{
        printf("Wrong! The answer is %d\n", a+b);system("pause");    
            }
        }
    ave = (float)scorep/item*100;
    printf("You got %d correct answers out of 5 for an average of %6.2f%%\n",scorep,ave);
    system("pause"); 
}

void minus ()
{
     for (i=0;i<item;i++){
        a = rand() % 20 + 10;
        b = rand() % 10 + 1;
    printf("%d.) %s, what is %d - %d = ? ", i+1,name,a,b);scanf("%d",&c);
    if (c == a - b){
    printf("Correct!\n");scorem++;system("pause");
        }
        else{
        printf("Wrong! The answer is %d\n", a-b);system("pause");    
            }
        }
    ave = (float)scorem/item*100;
    printf("You got %d correct answers out of 5 for an average of %6.2f%%\n",scorem,ave);
    system("pause"); 
}

void multi ()
{
    for (i=0;i<item;i++){
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
    printf("%d.) %s, what is %d * %d = ? ", i+1,name,a,b);scanf("%d",&c);
    if (c == a * b){
        printf("Correct!\n");scoret++;system("pause");
        }
        else{
        printf("Wrong! The answer is %d\n", a*b);system("pause");    
            }
        }
    ave = (float)scoret/item*100;
    printf("You got %d correct answers out of 5 for an average of %6.2f%%\n",scoret,ave);
    system("pause"); 

}

void divi ()
{
    for (i=0;i<item;i++){
        a = rand() % 20 + 10;
        b = rand() % 10 + 1;
    printf("%d.) %s what is %d / %d = ?(Whole number only!) ", i+1,name,a,b);scanf("%d",&c);
        if (c == a / b){
        printf("Correct!\n");scored++;system("pause");
        }
        else{
        printf("Wrong! The answer is %d\n", a/b);system("pause");    
            }
        }
    ave = (float)scored/item*100;
    printf("You got %d correct answers out of 5 for an average of %6.2f%%\n",scored,ave);
    system("pause"); 
}

int menu(){
int i,op;
char m[][31]={"Addition","Subraction","Division","Multiplication","Exit"};//Array of strings
system("cls");
gotoxy(45,4);
printf("MENU\n");
gotoxy(28,5);
printf("Choose what operation you want to solve?\n");
for (i=0;i<5;i++){
    gotoxy(35,7+i);
    printf("%d.) %s",i+1,m[i]);
}
gotoxy(35,8+i);
printf("Select(1-5): ");
scanf("%d",&op);
return op;
}

void gotoxy(int x,int y){
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

