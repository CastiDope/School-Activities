#include <iostream>
#define MAX 10
using namespace std;
int menu();
class MyClass {
private:
    string name[MAX];
    int q1[MAX];
    int q2[MAX];
    int q3[MAX];
    int marker;
    bool isFull();
    int locate(string n);
public:
    void init();
    void add(string n, int quiz1, int quiz2, int quiz3);
    void del(string n);
    void display();
    float average();
};

void MyClass::retrieve(){
fstream fp;
string n;
int qz1, qz2, qz3;

fp.open("studrec.txt",ios::in);
if (!fp){//fp is NULL
    cout <<"File error.\n";
    system("cls");
}
else {
     while (true){

        fp >> n>>qz1>>qz2>>qz3;
        if (!fp.eof())
          add(n,ag);

        else
          break;

    }
}
fp.close();
}
void MyClass::save(){
fstream fp;
fp.open("studrec.txt",ios::out);
if (!fp){//fp is NULL
    cout <<"File error.\n";
    system("cls");
}
else{
    for (int i = 0;i<=marker;i++)
        fp << name[i]<< " " << age[i]<< "\n";
}
fp.close();
}



void MyClass::init(){
    marker = -1;
}
void MyClass::add(string n, int quiz1, int quiz2, int quiz3){
if (isFull()){
    cout <<"Array is full."<<endl;
    system("pause");
}
marker++;
name[marker]=n;
q1[marker]=quiz1;
q2[marker]=quiz2;
q3[marker]=quiz3;
}
bool MyClass::isFull(){
  return(marker==MAX-1);
}
void MyClass::del(string n){
int p;
p=locate(n);
if (p<0){
    cout<<"Not found."<<endl;
    system("pause");
}
else {
    for (int i=p;i<marker;i++){
        name[i]=name[i+1];
        q1[i]=q1[i+1];
        q2[i]=q2[i+1];
        q3[i]=q3[i+1];
    }
    marker--;

  }
}
int MyClass::locate(string n){
for (int i=0;i<=marker;i++)
    if (name[i]==n)
       return i;
   return -1;
}
void MyClass::display(){
system("cls");
cout <<"   Name      Quiz#1      Quiz#2      Quiz#3"<<endl;
for (int i = 0;i<=marker;i++){
    cout <<i+1<<".) "<<name[i]<<"     "<<q1[i]<<"          "<<q2[i]<<"          "<<q3[i]<<endl;
}
system("pause");
}
int main(){
string nm;
int qi, qii, qiii, ch;
MyClass face;
face.init();
while (true){
    ch=menu();
    switch(ch){
       case 1: cout <<"Input name: "; cin >> nm;*/cin.ignore();getline(cin,nm);cout <<"Input Quiz#1: ";cin >> qi;cout <<"Input Quiz#2: ";cin >> qii;cout <<"Input Quiz#3: ";cin >> qiii;face.add(nm,qi,qii,qiii);break;
       case 2: cout <<"Input name: "; cin >> nm;face.del(nm);break;
       case 3: face.display();break;
       case 4: exit(0);
       default: cout<<" 1-4 only.\n";system("pause");

    }
}
return 0;
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
