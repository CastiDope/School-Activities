//C version of the Student Record Program using Link list implementation of ADT list
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

typedef struct node {
    char name[31];
    int quiz1, quiz2, quiz3;
    struct node* nxt;
} LIST;
LIST *L;

float average(int q1, int q2, int q3);

void makenull(){
    L = NULL;
}
void insert(char* nm, int q1, int q2, int q3){
LIST *p, *q, *temp;
p=q=L;
temp = (LIST*) ((malloc(sizeof(LIST))));
strcpy(temp-> name, nm);
temp->quiz1= q1;
temp->quiz2= q2;
temp->quiz3= q3;
while (p!=NULL && strcmp(p-> name,nm)<0){
    q=p;
    p=p->nxt;
}
if (p==L)//first element
    L=temp;
else
    q->nxt = temp;
temp->nxt = p;
}
void del (char* nm){
LIST *p, *q;
p=q=L;
while(p!=NULL && strcmp(p-> name,nm)!=0){
    q=p;
    p=p->nxt;
}
if (p==NULL){
    printf("Not found.");
    getch();
}
else{
    if (p==L)//if first element
       L=p->nxt;
    else
       q->nxt=p->nxt;
    free(p);
    }
}
void display(){
LIST *p;
int i = 1;
p=L;
float avg;
system("cls");
printf("    Name\tQuiz#1\tQuiz#2\tQuiz#3\tAverage\tRemarks\n");
while (p!=NULL){
    avg = average(p->quiz1,p->quiz2,p->quiz3);
    printf("%d.)%s \t%d\t%d\t%d\t%6.2f\t%s\n",i++,p-> name,p->quiz1,p->quiz2,p->quiz3,avg,avg>=75? "PASSED":"FAILED");
    p=p->nxt;
 }
 system("pause");
}

float average(int q1, int q2, int q3)
{
    return ((q1+q2+q3)/3.0);
}


int menu(){
int op;
system("cls");
printf("Menu\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Select(1-4): ");
scanf("%d",&op);
return(op);

}
int main(){
char nm[31];
int q1,q2,q3;
makenull();//initialize the list L
while(1){
    switch(menu()){
    case 1 : system("cls");printf("Insert Mode\n");
             printf("Enter Name: ");scanf(" %[^\n]s", nm);
                printf("Enter Quiz1: "); scanf("%d", &q1);
                printf("Enter Quiz2: "); scanf("%d", &q2);
                printf("Enter Quiz3: "); scanf("%d", &q3);
                insert(nm,q1,q2,q3);break;
    case 2 : system("cls");printf("DELETE MODE\n");
             printf("\nEnter  name: ");scanf(" %[^\n]s",nm);del(nm);break;
    case 3 : display();break;
    case 4 : exit(0);
    default:printf("1 to 4 only.");getch();
    }
  }
}
