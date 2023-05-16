#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
//Array of structures
typedef struct person {
    char name[31];
    int age;
    int points;
} PREC;
PREC face[MAX];//ARRAY OF STRUCTURE
int marker;

void init();
void getRec(PREC *pr);//pass-by reference
void add(PREC pr);
void del(char n[31]);
void display();
int isFull();
int locate(char n[31]);
int menu();
int isOld(int a);
void save();
void retrieve();
void update(char n[31]);

int main(){
PREC x;//structure variable
init();
retrieve(); //populate the array from the file
while (1){//infinite loop -> always true
   switch(menu()){
   case 1 : getRec(&x);add(x);break;
   case 2 : system("cls");printf("Input name : ");scanf(" %[^\n]s",x.name);update(x.name);break;
   case 3 : system("cls");printf("Input name : ");scanf(" %[^\n]s",x.name);del(x.name);break;
   case 4 : display();break;
   case 5 : save();exit(0);
   default: printf("1-4 lang!!!\n");system("pause");
  }
}
return 0;
}
void init(){
 marker = -1;
}
void add(PREC pr){
if (isFull()){
    printf("Puno na!\n");
    system("pause");
}
else {
    marker++;
    face[marker] = pr;
/*    strcpy(name[marker],n);
    age[marker]=a;
    points[marker]=pt;*/
//    printf("\n%Record of %s is added successfully.\n",n);
//    system("pause");
}

}
void del(char n[31]){
int p,i;
p=locate(n);
if (p<0){
    printf("Wala.\n");
    system("pause");
}
else {
    for (i=p;i<marker;i++){
            face[i]=face[i+1];
 /*       strcpy(name[i],name[i+1]);
        age[i]=age[i+1];
        points[i]=points[i+1];*/
    }
    marker--;
    printf("\nRecord of %s is deleted successfully.\n",n);
    system("pause");
    }
}
void display(){
int i,f;
system("cls");
printf("  Name\tAge\tPoints\tRemarks\n");
for (i=0;i<=marker;i++){
    f = isOld(face[i].age);
    printf("%d.) %s\t%d\t%d\t%s\n",i+1,face[i].name,face[i].age,face[i].points,f? "Old":"Young");
 }
system("pause");
}
int isFull(){
if (marker==MAX-1)
    return 1;
else
    return 0;
//return(marker==MAX-1);
}
int locate(char n[31]){
int i;
for (i=0;i<=marker;i++)
    if (strcmp(face[i].name,n)==0)
          return i;
return -1;

}
int menu(){
int op;
system("cls");
printf("MENU\n");
printf("1. Add record\n");
printf("2. Update a record\n");
printf("3. Delete record\n");
printf("4. Display All\n");
printf("5. Exit\n");
printf("Select(1-5): ");
scanf("%d",&op);
return op;
}
int isOld(int a){
  return(a>=18);
}
void save(){
FILE *fp; // define the file pointer
int i;
fp = fopen("bsit1ab.txt","w+");
if (fp==NULL){
    printf("File error.\n");
    system("pause");
  }
else {
    for (i=0;i<=marker;i++)
        fprintf(fp,"%s\n%d %d\n",face[i].name,face[i].age,face[i].points);
    fclose(fp);
   }
}
void retrieve(){
FILE *fp;
PREC y;
fp = fopen("bsit1ab.txt","r+");
if (fp==NULL){
    printf("File error.\n");
    system("pause");
  }
else {
    while (!feof(fp)){
        fscanf(fp,"%[^\n]s\n",y.name);
        fscanf(fp,"%d %d\n",&y.age,&y.points);
        add(y);
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
    while (ch!=3){

       printf("Name: %s\n",face[p].name);
       printf("Age: %d\n",face[p].age);
       printf("Points: %d\n",face[p].points);
       printf("Select item to update\n");
       printf("1. Age\n");
       printf("2. Points\n");
       printf("3. Return to main\n");
       printf("Input option(1-3): ");
       scanf("%d",&ch);
       switch(ch){
         case 1: printf("\nInput new age: ");scanf("%d",&face[p].age);break;
         case 2: printf("\nInput new points: ");scanf("%d",&face[p].points);break;
         case 3: break;
       }
     display();
    }
  }

}
void getRec(PREC* pr){//use '->' operator to access pointer to structure variable
system("cls");
printf("Input name : ");scanf(" %[^\n]s",pr->name);
printf("Input age : ");scanf("%d",&pr->age);
printf("Input points : ");scanf("%d",&pr->points);
}
