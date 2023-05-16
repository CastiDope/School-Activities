#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

char name[MAX][31];
int Q1[MAX], Q2[MAX], Q3[MAX];
int marker;
float compAve(int s1, int s2, int s3);


void init();
void add(char n[31], int q1, int q2, int q3);
void del(char n[31]);
void display();
int isFull();
int locate(char n[31]);
int menu();
void save();
void retrieve();
void update(char n[31]);
int searchpos(char n[31]);


int main()
{
    char nn[31];
    int q1, q2, q3;

    init();
    retrieve();
    while (1)
    {
        switch(menu())
        {
            case 1: system("cls");
            printf("Enter your name: ");
            scanf("%s", nn);
            printf("Enter QUIZ 1 Score: ");
            scanf("%d", &q1);
            printf("Enter QUIZ 2 Score: ");
            scanf("%d", &q2);
            printf("Enter QUIZ 3 Score: ");
            scanf("%d", &q3);
            add(nn, q1, q2, q3);break;
            
            case 2: system("cls");
            printf("Enter the name of the record that you want to delete: ");
            scanf("%s", nn);
            del(nn);break;
            
            case 3: system("cls");
            printf("Enter the name of the record that you want to update: ");
            scanf("%s", nn);
            update(nn);break;
            
            case 4: display();break;
            
            case 5: save();exit (0);
            
            default: printf("\nINVALID\n");
            system("pause");
        }
    }
    return 0;
}


void init()
{
    marker = -1;
}


void add(char n[31], int q1, int q2, int q3)
{
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
            Q1[i+1] = Q1[i];
            Q2[i+1] = Q2[i];
            Q3[i+1] = Q3[i];
        }
        strcpy(name[p],n);
        
        Q1[p]=q1;
        Q2[p]=q2;
        Q3[p]=q3;
        marker++;
    }
}


void del(char n[31])
{
    int i;
    int p;
    p = locate(n);

    if (p<0)
    {
        printf("No records found\n");
        system("pause");
    }

    else
    {
        for(i=p;i<marker;i++)
            strcpy(name[i], name[i+1]);
            Q1[i] = Q1[i+1];
            Q2[i] = Q2[i+1];
            Q3[i] = Q3[i+1];
        marker = marker -1;

        printf("%s's record was deleted successfully. . .\n", n);
        system("pause");
    }
}


void display()
{
    int i;
    float ave;

    system("cls");
    printf("\tNAME\t\tQUIZ 1\tQUIZ 2\tQUIZ 3\tAVERAGE\tREMARKS\n");

    for (i=0;i<=marker;i++)
    {
        ave = compAve(Q1[i], Q2[i], Q3[i]);
        printf("%d.) %s\t\t%d\t%d\t%d\t%6.2f\t%s\n", i+1, name[i], Q1[i], Q2[i], Q3[i], ave, ave>=75? "PASSED":"FAILED");
    }
    system("pause");
}


int isFull()
{
    return(marker==MAX-1);

}


int locate(char n[31])
{
    int i;

    for(i=0;i<=marker;i++)
        if(strcmp(name[i], n)==0)
        return(i);

    return -1;
}


int menu()
{
    int ch;
    system("cls");

    printf("      ~MENU~\n");
    printf("1) ADD A RECORD\n");
    printf("2) DELETE A RECORD\n");
    printf("3) UPDATE A RECORD\n");
    printf("4) DISPLAY ALL RECORDS\n");
    printf("5) EXIT PROGRAM\n");

    printf("\nSELECT(1-5): ");
    scanf("%d", &ch);

    return(ch);
}


float compAve(int s1, int s2, int s3)
{
    return((s1+s2+s3)/3.0);
}



void save()
{
    FILE *fp;
    int i;

    fp = fopen("BSIT1AB.txt","w+");
    if(fp==NULL){
        printf("FILE ERROR\n");
        system("pause");
    }
    else{
        for(i=0;i<=marker;i++)
        fprintf(fp,"%s %d %d %d\n", name[i], Q1[i], Q2[i], Q3[i]);

        fclose(fp);
    }
}


void retrieve()
{
    FILE *fp;
    char n[31];
    int q1, q2, q3;

    fp = fopen("BSIT1AB.txt","r+");
    if (fp==NULL){
        printf("Press any key to run the program\n");
        system("pause");
    }
    else{
        while (!feof(fp)){
            fscanf(fp,"%s %d %d %d\n", n, &q1, &q2, &q3);
            add(n,q1,q2,q3);
        }
        fclose(fp);
    }
}


void update(char n[31]){
    int p;
    int ch;

    p = locate(n);

    if (p<0){
        printf("Record does not exist\n");
        system("pause");
    }
    else{
        while (ch!=4){
            printf("Name: %s\n", name[p]);
            printf("QUIZ 1 Score: %d\n", Q1[p]);
            printf("QUIZ 2 Score: %d\n", Q2[p]);
            printf("QUIZ 3 Score: %d\n", Q3[p]);
            printf("Select item to update:\n");
            printf("1. QUIZ 1 Score\n");
            printf("2. QUIZ 2 Score\n");
            printf("3. QUIZ 3 Score\n");
            printf("4. Return to Menu\n");
            printf("\nSELECT(1-4): ");
            scanf("%d", &ch);

            switch(ch){
                case 1: printf("Enter new QUIZ 1 Score: ");scanf("%d", &Q1[p]);break;
                case 2: printf("Enter new QUIZ 2 Score: ");scanf("%d", &Q2[p]);break;
                case 3: printf("Enter