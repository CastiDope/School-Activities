//ARRAY OF STRUCTURES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAX 50
void gotoxy(int x,int y);
typedef struct rec {
   char name[31];
   int age;
   int points;
} REC;
REC stude[MAX];//array of structures
int marker;

void init();
void getRec(REC *st);
void add(REC sr);
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
REC x;
init();
retrieve();//to populate the arrays
while (1){//infinite loop -> always true
   switch(menu()){
   case 1 : getRec(&x);add(x);break;
   case 2 : system("cls");printf("Input name : ");scanf("%s",x.name);update(x.name);break;
   case 3 : system("cls");printf("Input name : ");scanf("%s",x.name);del(x.name);break;
   case 4 : display();break;
   case 5 : save();exit(0);
   default: printf("1-5 lang!!!\n");system("pause");
  }
}
return 0;
}
void init(){
 marker = -1;
}
void add(REC sr){
if (isFull()){
    printf("Puno na!\n");
    system("pause");
}
else {
    marker++;
    stude[marker] = sr;
/*    strcpy(name[marker],n);
    age[marker]=a;
    points[marker]=p;*/
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
        stude[i]=stude[i+1];
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
gotoxy(15,5);printf("Name");
gotoxy(45,5);printf("Age");
gotoxy(55,5);printf("Points");
gotoxy(65,5);printf("Remarks");

for (i=0;i<=marker;i++){
    f = isOld(stude[i].age);
    gotoxy(10,7+i);printf("%d.)",i+1);
    gotoxy(15,7+i);printf("%s",stude[i].name);
    gotoxy(45,7+i);printf("%d",stude[i].age);
    gotoxy(55,7+i);printf("%d",stude[i].points);
    gotoxy(65,7+i);printf("%s",f? "Old":"Young");

 }
gotoxy(10,8+i);system("pause");
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
    if (strcmp(stude[i].name,n)==0)
          return i;
return -1;

}
int menu(){
int i,op;
char m[][31]={"Add record","Update record","Delete record","Display All","Exit"};//Array of strings
system("cls");
gotoxy(40,5);
printf("MENU\n");
for (i=0;i<5;i++){
    gotoxy(35,7+i);
    printf("%d.) %s",i+1,m[i]);
}
gotoxy(35,8+i);
printf("Select(1-5): ");
scanf("%d",&op);
return op;
}
int isOld(int a){
  return(a>=18);
}

void save(){
FILE *fp;
int i;
fp = fopen("bscs1ab.txt","w+");
if (fp==NULL){
    printf("File error.\n");
    system("pause");
}
else {
    for (i=0;i<=marker;i++)
        fprintf(fp,"%s %d %d\n",stude[i].name,stude[i].age,stude[i].points);
    fclose(fp);
}

}
void retrieve(){
FILE *fp;
REC y;
fp = fopen("bscs1ab.txt","r+");
if (fp==NULL){
    printf("File error.\n");
    system("pause");
}
else {
    while (!feof(fp)){
        fscanf(fp,"%s %d %d\n",y.name,&y.age,&y.points);
        add(y);
    }
    fclose(fp);
}
}
void update(char n[31]){
int p,ch;
p = locate(n);
if (p<0){
    printf("No such record.\n");
    system("pause");
}
else {
    while(ch!=3){
        system("cls");
        printf("Name: %s\n",stude[p].name);
        printf("Age: %d\n",stude[p].age);
        printf("Points: %d\n",stude[p].points);
        printf("Select item to update\n");
        printf("1. Age\n");
        printf("2. Points\n");
        printf("3. Return to main\n");
        printf("Select(1-3): ");
        scanf("%d",&ch);
        switch(ch){
          case 1: printf("Input new age: ");
                  scanf("%d",&stude[p].age);break;
          case 2: printf("Input new Points: ");
                  scanf("%d",&stude[p].points);break;
          case 3: break;
        }

    }
  }
}
void gotoxy(int x,int y){
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void getRec(REC *st){
system("cls");
gotoxy(40,5);printf("Insert Record Mode");
gotoxy(35,7);printf("Input Name: ");scanf("%s",st->name);
gotoxy(35,8);printf("Input Age: ");scanf("%d",&st->age);
gotoxy(35,9);printf("Input Points: ");scanf("%d",&st->points);

}
