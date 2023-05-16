#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

char name[MAX][31];
int quiz1[MAX],quiz2[MAX],quiz3[MAX];
int marker;
float ave;

void init();
void add(char n[31], int q1, int q2, int q3);
void del(char n[31]);
void display();
void computeAve();
float average(int a, int b, int c);
int isFull();
int locate(char n[31]);
int menu();

int main(){
char nn[31];
int a, b, c;
init();
while (1){
    switch(menu()){
        case 1 : system("cls");printf("Enter name: ");scanf("%s", nn);printf("Input Quiz1: ");scanf("%d", &a);printf("Enter Quiz2: ");scanf("%d", &b);printf("Enter Quiz3: ");scanf("%d", &c);add(nn, a, b, c);break;
        case 2 : system("cls");printf("Enter name in the record to delete: ");scanf("%s", nn);del(nn);break;
        case 3 : display();break;
        case 4 : exit (0);
        default: printf("\n Only 1-4 can be chosen.\n");system("pause");
    }
}
return 0;
}

void init(){
  marker = -1;
}
void add(char n[31], int q1, int q2, int q3){

if (isFull()){
    printf("Puno na.\n");
    system("pause");
}
else{
    marker = marker + 1;
    strcpy(name[marker],n);
    quiz1[marker]=q1;
    quiz2[marker]=q2;
    quiz3[marker]=q3;
    printf("Record of %s is added successfully.\n",n);
    system("pause");
    }

}

void del(char n[31]){
int i,p;
p = locate(n);
if (p<0){
    printf("Waley.\n");
    system("pause");
  }
else {
    for (i=p;i<marker;i++)
        strcpy(name[i],name[i+1]);
        quiz1[i]=quiz1[i+1];
        quiz2[i]=quiz2[i+1];
        quiz3[i]=quiz3[i+1];
    marker = marker -1;
    printf("Record of %s was deleted successfully.\n",n);
    system("pause");
    }
 }

void display(){
int i;
system("cls");
printf("    NAME\tQuiz1\tQuiz2\tQuiz3\tAverage\tRemarks\n");
for (i=0;i<=marker;i++){
    ave = average(quiz1[i],quiz2[i],quiz3[i]);
    printf("%d.)%s\t\t%d\t%d\t%d\t%6.2f\t%s\n",i+1,name[i],quiz1[i],quiz2[i],quiz3[i],ave,ave>=75? "PASSED":"FAILED");
    }
system("pause");
}
int isFull(){
return (marker==MAX-1);
}
int locate(char n[31]){
int i;
for (i=0;i<=marker;i++)
    if (strcmp(name[i],n)==0)
        return (i);
return -1;
}

float average(int a, int b, int c)
{
        return( (a+b+c)/3.0 );
}


int menu(){
int op;
system("cls");
printf("MENU\n");
printf("1. Add student record\n");
printf("2. Delete a student record\n");
printf("3. Display all student record\n");
printf("4. Exit\n");
printf("Select(1-4): ");
scanf("%d",&op);
return(op);
}
