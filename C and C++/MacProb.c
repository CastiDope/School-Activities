#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

char name[MAX][31];
int quiz1[MAX],quiz2[MAX],quiz3[MAX];
int marker;
float ave;

void init();
void add(char n[31], int q1, int q2, int q3);
void del(char n[31]);
void display();
void computeAve();
void save();
void retrieve();
void update(char n[31]);
float average(int a, int b, int c);
int isFull();
int searchpos(char n[31]);
int locate(char n[31]);
int menu();

int main(){
char nn[31];
int a, b, c;
init();
retrieve();
while (1){
    switch(menu()){
        case 1 : system("cls");printf("Enter name: ");scanf("%s", nn);printf("Input Quiz1: ");scanf("%d", &a);printf("Enter Quiz2: ");scanf("%d", &b);printf("Enter Quiz3: ");scanf("%d", &c);add(nn, a, b, c);break;
        case 2 : system("cls");printf("Enput name : ");scanf("%s",nn);update(nn);break;
        case 3 : system("cls");printf("Enter name in the record to delete: ");scanf("%s", nn);del(nn);break;
        case 4 : display();break;
        case 5 : save();exit (0);
        default: printf("\n Only 1-4 can be chosen.\n");system("pause");
    }
}
return 0;
}

void init(){
  marker = -1;
}
void add(char n[31], int q1, int q2, int q3){
int p,i;
if (isFull()){
    printf("Puno na.\n");
    system("pause");
}
else{
    int i;
    int p;

    if (isFull())
    {
        printf("The record is full. . .\n");
        system("pause");
    }
    else
    {
        p = searchpos(n);
        for (i=marker; i>=p; i--){
            strcpy(name[i+1], name[i]);
            quiz1[i+1] = quiz1[i];
            quiz2[i+1] = quiz2[i];
            quiz3[i+1] = quiz3[i];
        }
        strcpy(name[p],n);

        quiz1[p]=q1;
        quiz2[p]=q2;
        quiz3[p]=q3;
        marker++;
    }
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
printf("   NAME \tQuiz1\tQuiz2\tQuiz3\tAverage\tRemarks\n");
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
printf("2. Update a record\n");
printf("3. Delete a student record\n");
printf("4. Display all student record\n");
printf("5. Exit\n");
printf("Select(1-4): ");
scanf("%d",&op);
return(op);
}

void save(){
FILE *fp; // define the file pointer
int i;
fp = fopen("studrec.txt","w+");
if (fp==NULL){
    printf("File error.\n");
    system("pause");
  }
else {
    for (i=0;i<=marker;i++)
    fprintf(fp,"%s %d %d %d\n",name[i],quiz1[i], quiz2[i], quiz3[i]);
    fclose(fp);
   }
}
void retrieve(){
FILE *fp;
char n[31];
int q1, q2, q3;
float avg;
fp = fopen("studrec.txt","r+");
if (fp==NULL){
    printf("File error.\n");
    system("pause");
  }
else {
    while (!feof(fp)){
        fscanf(fp,"%s %d %d %d %6.2f %s\n",n,&q1,&q2,&q3);
        add(n,q1,q2,q3);
    }
    fclose(fp);
  }
}

void update(char n[31]){
int p,ch;
p = locate(n);
if (p<0){
    printf("Record not found.\n");
    system("pause");
}
else {
    while (ch!=4){
       printf("Name: %s\n",name[p]);
       printf("Quiz1: %d\n",quiz1[p]);
       printf("Quiz2: %d\n",quiz2[p]);
       printf("Quiz3: %d\n",quiz3[p]);
       printf("Select item to update\n");
       printf("1. Quiz 1\n");
       printf("2. Quiz 2\n");
       printf("3. Quiz 2\n");
       printf("4. Return to main\n");
       printf("Input option(1-3): ");
       scanf("%d",&ch);
       switch(ch){
         case 1: printf("\nInput new Quiz1 Points: ");scanf("%d",&quiz1[p]);break;
         case 2: printf("\nInput new Quiz2 Points: ");scanf("%d",&quiz2[p]);break;
         case 3: printf("\nInput new Quiz1 Points: ");scanf("%d",&quiz1[p]);break;
         case 4: break;
       }
     display();
    }
  }
}

int searchpos(char n[31]){
int i;
for (i=0;i<=marker;i++)
    if (strcmp(n, name[i])<0)
        return i;
return i;
}
