#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct node{
    char  name[30];
    int q1;
    int q2;
    int q3;
struct node *next;
}NODE;
NODE *head;

void init();

void del(char*  name);
void display();
void retrieve();
void save();

float average(int q1, int q2, int q3);
int menu();

void init()
{
    head = NULL;
}

int main()
{
    char  name[30];
    int q1;
    int q2; 
    int q3;

    init();
    retrieve();
    while(1){
        switch(menu()){
        case 1 : system("cls");printf("INSERT MODE\n");
                printf("Enter Name: ");scanf(" %[^\n]s", name);
                printf("Enter Quiz1: "); scanf("%d", &q1);
                printf("Enter Quiz2: "); scanf("%d", &q2);
                printf("Enter Quiz3: "); scanf("%d", &q3);
                add(name,q1,q2,q3);break;
        case 2 : system("cls");printf("DELETE MODE\n");
                printf("\nEnter  name: ");scanf(" %[^\n]s", name);del( name);break;
        case 3 : display();break;
        case 4 : save(); exit(0);
        default: printf("1 to 4 only.");system("pause");
        }
    }
    return 0;
}

void add(char* nm, int q1, int q2, int q3)
{
    NODE *p,*q,*n;
    p=q=head;

    n = (NODE*)(malloc(sizeof(NODE)));
    strcpy(n-> name, nm);
    n->q1 = q1;
    n->q2 = q2;
    n->q3 = q3;

    while (p!=NULL && strcmp(p-> name,nm)<0){
        q=p;
        p=p->next;
    }

    if (p==head)
        head = n;
    else {
        q->next = n;
    }
        n->next = p;
}

void del(char*  name)
{
    NODE *p,*q;
    p=q=head;
    while (p!=NULL && strcmp(p-> name,  name)!=0){
        q=p;
        p=p->next;
    }
    if (p==NULL){
        printf("%s is not in the list.\n", name);
        system("pause");
    }
    else {
        if (p==head)
            head = p->next;
        else
            q->next = p->next;
    }
        free(p);
}

void display()
{
    NODE* p;
    int i = 1;
    float avg;
    p=head;
    system("cls");
    printf("    NAME\tQUIZ1\tQUIZ2\tQUIZ3\tAVERAGE\tREMARKS\n");
    while (p!=NULL){
        avg = average(p->q1,p->q2,p->q3);
        printf("%d.)%s \t\t%d\t%d\t%d\t%6.2f\t",i++,p-> name,p->q1,p->q2,p->q3,avg);
        printf(avg>=75? "PASSED\n":"FAILED\n");
        p=p->next;
    }
    system("pause");
}

float average(int q1, int q2, int q3)
{
    return ( (q1+q2+q3)/3.0);
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

void retrieve(){

    FILE *fp;
    char  name[30];
    int q1,q2,q3;

    fp = fopen("studrec.txt","r+");

if (fp==NULL){
    fclose(fp);
    printf("File error.\n");
    system("pause");
  }
else {
    while (!feof(fp)){
        fscanf(fp," %[^\n]s\n",& name);
        fscanf(fp,"%d %d %d\n",&q1,&q2,&q3);
        add( name,q1,q2,q3);
    }
    fclose(fp);
    printf("\n");
  }
}

void save(){
    system("cls");

    NODE* p;
    p=head;

    FILE *fp;
    fp = fopen("studrec.txt","w+");

    if (fp==NULL)
    {
        printf("\nFile error.\n");
        fclose(fp);
    }
    else {
    while (p!=NULL)
    {
        fprintf(fp,"%s\n%d\t%d\t%d\n",p-> name,p->q1,p->q2,p->q3);
        p=p->next;
    }
        fclose(fp);
        printf("Data has been successfully saved.\n");
    }
    system("pause");
}