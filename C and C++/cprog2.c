#include <stdio.h>
#include <stdlib.h>
#define MAX 2
char name[MAX][31];
int q1[MAX],q2[MAX],q3[MAX],i;
float ave;

void getRecord();
void computeAve();
void display();

int main()
{
    getRecord();
    computeAve();
    display();

    return 0;
}

void getRecord(){
int i;
for (i=0;i<MAX;i++)
    {
    printf("\nName: ");
    scanf(" %[^\n]s",name[i]);
    printf("Input quiz1: ");
    scanf("%d",&q1[i]);
    printf("Input quiz2: ");
    scanf("%d",&q2[i]);
    printf("Input quiz3: ");
    scanf("%d",&q3[i]);
    }
}

void computeAve(){
int i;
ave = (q1[i]+q2[i]+q3[i])/3.0;
}

void display(){
int i;
system("cls");
printf("    NAME\tQuiz1\tQuiz2\tQuiz3\tAverage\tRemarks\n");
for (i=0;i<MAX;i++ )
    {
    ave = (q1[i]+q2[i]+q3[i])/3.0;
    printf("%d.) %s\t%d\t%d\t%d\t%6.2f\t%s\n",i+1,name[i],q1[i],q2[i],q3[i],ave,ave>=75? "PASSED":"FAILED");
    }
}
