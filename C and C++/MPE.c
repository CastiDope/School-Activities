//Array of integers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
//Global variables
int q1,q2,q3;
char nn[31];
char name[MAX][31];
int quiz1[MAX],quiz2[MAX],quiz3[MAX];
float Average(int a, int b, int c);
float average;
int marker;
//functions
void init();
void add(char n[31], int q1, int q2, int q3);
void del(char n[31]);
void display();
int isFull();
int locate(char n[31]);
int menu();

int main(){
int d;
init();
while (1){
    switch(menu()){
        case 1 : system("cls");printf("Enter name: ");scanf(" %[^\n]s",nn);printf("input q1: ");scanf("%d",&q1);printf("input q2: ");scanf("%d",&q2);printf("input q3: ");scanf("%d",&q3);add(nn,q1,q2,q2);break;
        case 2 : system("cls");printf("Enter name of record to delete: ");scanf(" %[^\n]s",nn);del(nn);break;
        case 3 : display();break;
        case 4 : exit (0);
        default: printf("\n 1-4 langs.\n");system("pause");
    }
}
return 0;
}
//function definitions
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
    printf("record of %s is added successfully.\n",n);
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
    printf("record of %s was deleted successfully.\n",n);
    system("pause");
    }
 }

void display(){
int i;
system("cls");
printf("\tNAME\t\tQUIZ1\tQUIZ2\tQUIZ3\tAVERAGE\tREMARKS\n");
for (i=0;i<=marker;i++){
    average = Average(quiz1[i],quiz2[i],quiz3[i]);
    printf("%d). %s\t\t%d\t%d\t%d\t%6.2f\t%s\n",i+1,name[i],quiz1[i],quiz2[i],quiz3[i], average, average>=75? "PASSED":"FAILED");
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
int menu(){
int op;
system("cls");
printf("MENU\n");
printf("1. Add record\n");
printf("2. Delete a record\n");
printf("3. Display All\n");
printf("4. Exit na\n");
printf("Select(1-4): ");
scanf("%d",&op);
return(op);
}

float Average(int a, int b, int c)
 {
    return ( (a+b+c)/3.0);
 }
