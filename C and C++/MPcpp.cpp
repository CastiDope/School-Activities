//C++ version of the Student Record Program using Link list implementation of ADT list
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
typedef struct node{
   string name;
   int quiz1, quiz2, quiz3;
   struct node *nxt;
}LIST;
class MyLinkList{
private:
    LIST *L;
public:
    void makenull();
    void add(string n, int q1, int q2, int q3);
    void del(string n);
    void display();
};
void MyLinkList::makenull(){
  L = NULL;
}
void MyLinkList::add(string n, int q1, int q2, int q3){
LIST *p, *q, *temp;
p=q=L;
temp = new LIST;
temp->name = n;
temp->quiz1= q1;
temp->quiz2= q2;
temp->quiz3= q3;

while (p!=NULL && n > p->name){
    q=p;
    p=p->nxt;
}
if (p==L)
    L = temp;
else
    q->nxt = temp;
temp->nxt=p;
}
void MyLinkList::del(string n){
LIST *p, *q;
p=q=L;
while (p!=NULL && p->name!=n){
    q=p;
    p=p->nxt;
}
if (p==NULL){
    cout <<"Not found!\n";
    system("pause");
   }
else {
    if (p==L)
        L = p->nxt;
    else
        q->nxt = p->nxt;
    free(p);
  }
}

void MyLinkList::display(){
int i = 1;
LIST *p;
p=L;
system("cls");
cout <<"     Name       Quiz#1      Quiz#2      Quiz#3      Average      Remarks"<<endl;
while(p!=NULL){
    float avg = ceil((p->quiz1+p->quiz2+p->quiz3)/3.0);
    cout <<i++<<".) "<<p->name<<"       "<<p->quiz1<<"          "<<p->quiz2<<"          "<<p->quiz3<<"          "<<avg<<"          "<<((avg>=75) ? "PASSED":"FAILED")<<endl;
    p=p->nxt;
}
system("pause");
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
MyLinkList face;
face.makenull();
while (true){
    ch=menu();
    switch(ch){
       case 1: cout <<"Input name: "; cin.ignore();getline(cin,nm);cout <<"Input Quiz#1: ";cin >> q1;cout <<"Input Quiz#2: ";cin >> q2;cout <<"Input Quiz#3: ";cin >> q3;face.add(nm,q1,q2,q3);break;
       case 2: cout <<"Input name: "; cin >> nm;face.del(nm);break;
       case 3: face.display();break;
       case 4: exit(0);
       default: cout<<" 1-4 only.\n";system("pause");

        }
    }
}