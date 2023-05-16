#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
typedef struct node{
   string name;
   int quiz1, quiz2, quiz3;
   struct node *next;
}NODE;
class Mylink{
private:
    NODE *head;
    bool isEmpty();
public:
    void init();
    void add(string n, int q1, int q2, int q3);
    void del(string n);
    void display();
    void save();
    void retrieve();
};
void Mylink::init(){
  head = NULL;
}
void Mylink::add(string n, int q1, int q2, int q3){
NODE *p, *q, *newNode;
p=q=head;
//newNode =(NODE*) malloc(sizeof(NODE));
newNode = new NODE;
//strcpy(newNode->name , n);
//newNode.assign(newNode->name,n);
newNode->name = n;
newNode->quiz1= q1;
newNode->quiz2= q2;
newNode->quiz3= q3;

//locate the last element
while (p!=NULL && n > p->name){
    q=p;
    p=p->next;
}
if (p==head)
    head = newNode;//first element
else
    q->next = newNode;
newNode->next=p;
}
void Mylink::del(string n){
NODE *p, *q;
p=q=head;
while (p!=NULL && p->name!=n){
    q=p;
    p=p->next;
}
if (p==NULL){
    cout <<"Not found!\n";
    system("pause");
   }
else {
    if (p==head)
        head = p->next;
    else
        q->next = p->next;
    free(p);
  }
}
bool Mylink::isEmpty(){
  return(head == NULL);
}
void Mylink::display(){
int i = 1;
NODE *p;
p=head;
float avg = ceil((p->quiz1+p->quiz2+p->quiz3)/3.0);
system("cls");
cout <<"     Name       Quiz#1      Quiz#2      Quiz#3      Average      Remarks"<<endl;
while(p!=NULL){
    cout <<i++<<".) "<<p->name<<"       "<<p->quiz1<<"          "<<p->quiz2<<"          "<<p->quiz3<<"          "<<avg<<"          "<<((avg>=75) ? "PASSED":"FAILED")<<endl;
    p=p->next;
}
system("pause");
}

void Mylink::retrieve(){
fstream fp;
string n;
int q1,q2,q3;
fp.open("studrec.dbf",ios::in);
if (!fp){//fp is NULL
    cout <<"File error.\n";
    system("cls");
}
else {
     while (true){

         getline(fp,n);
        fp >> q1>>q2>>q3;
        fp.ignore();
        if (!fp.eof())
          add(n,q1,q2,q3);

        else
          break;

        }
    }
fp.close();
}

void Mylink::save(){
fstream fp;
NODE *p;
p=head;
fp.open("studrec.dbf",ios::out);
if (!fp){//fp is NULL
    cout <<"File error.\n";
    system("cls");
}
else{
    while (p!=NULL){
    fp << p->name<< endl << p->quiz1<< endl << p->quiz2<< endl << p->quiz3<< endl;
    p=p->next;
        }
fp.close();
    }
}

int menu(){
int ch;
system("cls");
cout <<"      MENU"<<endl;
cout<<"1. Add Record"<<endl;
cout<<"2. Delete Record"<<endl;
cout<<"3. Display"<<endl;
cout<<"4. Exit"<<endl;
cout<<"Select(1-4): ";
cin >> ch;
return ch;
}

int main(){
string nm;
int q1, q2, q3, ch;
Mylink face;
face.init();
face.retrieve();
while (true){
    ch=menu();
    switch(ch){
       case 1: cout <<"Input name: ";/* cin >> nm;*/cin.ignore();getline(cin,nm);cout <<"Input Quiz#1: ";cin >> q1;cout <<"Input Quiz#2: ";cin >> q2;cout <<"Input Quiz#3: ";cin >> q3;face.add(nm,q1,q2,q3);break;
       case 2: cout <<"Input name: "; cin >> nm;face.del(nm);break;
       case 3: face.display();break;
       case 4: face.save();exit(0);
       default: cout<<" 1-4 only.\n";system("pause");

        }
    }
}