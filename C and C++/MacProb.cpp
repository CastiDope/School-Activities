#include <iostream>
#include <fstream>
#include <cstring>
#define MAX 10
using namespace std;

int menu();
typedef struct record {
    string name;
    int q1, q2, q3;
} REC;
//DATA STRUCTURE
typedef struct stude {
    REC sr [MAX];
    int last;
} LIST;

class MyList {
private:
    LIST L;
    bool isfull();
    bool isempty();
    int locate (string n);
    float avg;
public:
    void makenull();
    void add (REC x);
    void del (string n);
    void update (string n);
    void display();
    void save();
    void retrieve();
    void init();
};

void MyList::makenull(){
    L.last = -1;
}

void MyList::add(REC x){
REC stud;
if (isfull()){
    cout <<"Array is full."<<endl;
    system("pause");
}
L.last++;
L.sr[L.last]=x;
}
bool MyList::isfull(){
  return(L.last==MAX-1);
}

void MyList::del(string n){
int p;
p=locate(n);
if (p<0){
    cout<<"Not Found."<<endl;
    system("pause");
}
else {
    for (int i=p;i<L.last;i++){
        L.sr[i]=L.sr[i+1];
        
    }
    L.last--;

  }
}

int MyList::locate(string n){
for (int i=0;i<=L.last;i++)
    if (L.sr[i].name==n)
       return i;
   return -1;
}

void MyList::update(string n){
int p,ch;
REC up;
p=locate(n);
if (p<0){
    cout <<"Record not found."<<endl;
    system("pause");
}
else {
    while (ch!=4){
       cout <<"Name              Quiz#1              Quiz#2              Quiz#3" << endl;
       cout <<""<<L.sr[p].name<<"                 "<<L.sr[p].q1<<"                  "<<L.sr[p].q2<<"                  "<<L.sr[p].q3<<" "<< endl;
       cout <<"Select item to update" << endl;
       cout <<"1. Quiz 1"<< endl;
       cout <<"2. Quiz 2"<< endl;
       cout <<"3. Quiz 3"<< endl;
       cout <<"4. Return to main"<< endl;
       cout <<"Input option(1-4):  "; cin >> ch;break;
       switch(ch){
         case 1: cout <<"Input new Quiz1 Points: ";cin >> L.sr[p].q1;break;
         case 2: cout <<"Input new Quiz2 Points: ";cin >> L.sr[p].q2;break;
         case 3: cout <<"Input new Quiz3 Points: ";cin >> L.sr[p].q3;break;
         case 4: menu();break;
         default: cout<<" 1-4 only.\n";system("pause");
       }
    }
  }
}

void MyList::save(){
fstream fp;
fp.open("studrec.txt",ios::out);
if (!fp){//fp is NULL
    cout <<"File error.\n";
    system("cls");
}
else{
    for (int i = 0;i<=L.last;i++)
        fp << L.sr[i].name<< endl << L.sr[i].q1<< endl << L.sr[i].q2<< endl << L.sr[i].q3<< endl;
}
fp.close();
}

void MyList::retrieve(){
fstream fp;
REC ret;
fp.open("studrec.txt",ios::in);
if (!fp){//fp is NULL
    cout <<"No file record found.\n";
    system("pause");
    system("cls");
} 
else {
    while (true){

        getline(fp,ret.name);
        fp >> ret.q1>>ret.q2>>ret.q3;
        fp.ignore();
        if (!fp.eof())
          add(ret);
        
        else
          break;
    cout <<"Record successfully retrieved!\n";
    system("pause");
    }
}
fp.close();
}

void MyList::display(){
system("cls");
cout <<"     Name       Quiz#1      Quiz#2      Quiz#3      Average      Remarks"<<endl;
for (int i = 0;i<=L.last;i++){
    avg = (L.sr[i].q1+L.sr[i].q2+L.sr[i].q3)/3.0;
    cout <<i+1<<".)  "<<L.sr[i].name<<"          "<<L.sr[i].q1<<"          "<<L.sr[i].q2<<"          "<<L.sr[i].q3<<"          "<<avg<<"         "<<((avg>=75) ? "PASSED":"FAILED")<<endl;
}
system("pause");
}

int main(){
int ch;
REC stud;
MyList face;
face.makenull();
face.retrieve();
while (true){
    ch=menu();
    switch(ch){
       case 1: cout <<"Input name: ";/* cin >> nm;*/cin.ignore();getline(cin,stud.name);cout <<"Input Quiz#1: ";cin >> stud.q1;cout <<"Input Quiz#2: ";cin >> stud.q2;cout <<"Input Quiz#3: ";cin >> stud.q3;face.add(stud);break;
       case 2: cout <<"Input name: "; cin >> stud.name;face.update(stud.name);break;
       case 3: cout <<"Input name: "; cin >> stud.name;face.del(stud.name);break;
       case 4: face.display();break;
       case 5: face.save();exit(0);
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
cout<<"2. Update Record"<<endl;
cout<<"3. Delete Record"<<endl;
cout<<"4. Display"<<endl;
cout<<"5. Exit"<<endl;
cout<<"Select(1-5): ";
cin >> ch;
return ch;
}
