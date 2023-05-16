#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define MAX 50

using namespace std;

int item = 5;
int marker;

typedef struct stud{
    string username;
    string password;
    int scoreA,scoreS,scoreM,scoreD;
    float average;
}PREC;

PREC x[MAX];

class MyClass {
private:

    int locate(string n);
    int compare(string user, string pass);
    void design();
    void design2();

public:


    float ave (int a, int s, int d, int m);
    void save_Ave(string n);
    void act_login();
    void login_leaderboards();
    void ingame_leaderboards(string n);
    void add_rec(string n, string p, int a, int s, int m, int d, float av);
    void create_acc();
    void login();
    void retrieve();
    void save();
    int login_menu();
    int menu();
    int login_lead_menu();
    int ingame_lead_menu();
    void gotoxy(int x,int y);
    void arithmetic_game(string n);
    void addlboard();
    void sublboard();
    void mulboard();
    void divlboard();
    void overall();
    void add(string n);
    void subtract(string n);
    void multiply(string n);
    void divide(string n);
};


void MyClass::create_acc()
{

    int p,i;
    string un, pass;
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");
    design();
    gotoxy(55,2);cout<<"CREATE ACCOUNT "<<endl;
    gotoxy(45,6);cout << "Username: ";
    cin >> un;
    p=locate(un);

    if (p<0)
    {
        gotoxy(45,7);cout << "Password: ";
        cin >> pass;
        marker++;

        x[marker].username = un;
        x[marker].password = pass;

        system("cls");
        design();
        SetConsoleTextAttribute(h,10);
        gotoxy(40,9);cout << "Your account has been created.." << endl;
        SetConsoleTextAttribute(h,7);
        gotoxy(40,11);system("pause");
        SetConsoleTextAttribute(h,7);
    }

    while (p>=0)
    {
     system("cls");
     design();
     SetConsoleTextAttribute(h,12);
     gotoxy(40,11);cout << "\nUser ID" << un << "exist! Choose another one. . ." << endl;

        system("pause");
        SetConsoleTextAttribute(h,7);
        system("cls");
        design();

        gotoxy(55,2);cout<<"CREATE ACCOUNT "<<endl;
        gotoxy(45,6);cout << "Username: ";
        cin >> un;
        p=locate(un);

        if (p<0)
        {
            gotoxy(45,7);cout << "Password: ";
            cin >> pass;
            marker++;

            x[marker].username = un;
            x[marker].password = pass;

            system("cls");
            SetConsoleTextAttribute(h,10);
            gotoxy(40,9);cout << "Your account has been created.." << endl;
            SetConsoleTextAttribute(h,7);
            gotoxy(40,11);system("pause");
        }

    }
}


void MyClass::login()
{
    string un;
    string password;
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");
    design();
    gotoxy(59,2);cout<<"LOG IN "<<endl;

    gotoxy(50,7);cout << "Username: ";
    cin >> un;
    gotoxy(50,8);cout << "Password: ";
    cin >> password;


        while (compare(un,password)!=0)
        {

                SetConsoleTextAttribute(h,12);
                gotoxy(50,9);cout<<"<!> Incorrect Username or Password.."<<endl;
                SetConsoleTextAttribute(h,7);
                gotoxy(50,10);system("pause");
                system("cls");
                act_login();
        }
        while(compare(un,password)==0)
        {
            system("cls");
            design();

            SetConsoleTextAttribute(h,10);
            gotoxy(48,10);cout<<"Log In Successfully!\n";
            SetConsoleTextAttribute(h,7);
            gotoxy(48,11);system("pause");


            system("cls");
            design();
            gotoxy(42,5);cout<<"WELCOME PLAYER "<<un<<" IN ARITHMETIC GAME"<< endl;

            design2();
            SetConsoleTextAttribute(h,9);
            gotoxy(59,12);cout<<"PLAY"<< endl;
            SetConsoleTextAttribute(h,7);
            gotoxy(43,20);system("pause");
            arithmetic_game(un);
        }
}

void MyClass::add(string n)
{
    system("cls");
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

    int a, b, c;
    int i, p, temp;
    p = locate(n);

    int n = 0;

    srand (time(NULL));

    for (i=0;i<item;i++)
    {
            a = rand()% 10 + 1;
            b = rand()% 10 + 1;
        design();
        cout<<"ADDITION GAME\n"<<endl;

        cout << i+1 << ".) " << a << " + " << b << " = ?\n";
        cout<<"Answer: ";
        cin >> c;
        if(c == a+b)
            {
            cout << "Your answer is";SetConsoleTextAttribute(h,10);cout<<" CORRECT!" << endl;
            n++;
            SetConsoleTextAttribute(h,7);
            system("pause");
            system("cls");
            }
        else {
            SetConsoleTextAttribute(h,12);cout << "WRONG ANSWER!"<<endl;
            SetConsoleTextAttribute(h,7);cout<< "CORRECT ANSWER: " << a + b << endl;
            system("pause");
            system("cls");
            }
    }
    cout << "Total Score: " << n << " out of " << item << endl;
    cout << "Average: " << (float)a_score/item * 100 <<"%"<<endl;
    gotoxy(48,12);system("pause");

    if (x[p].scoreA <= a_score)
    {
        temp = x[p].scoreA;
        x[p].scoreA = a_score;
        a_score = temp;
    }
    save_Ave(n);
    addlboard();
}

void MyClass::addlboard()
{
    int i,a;
    PREC temp;


    system("cls");
    design();
    gotoxy(52,2);cout<<"ADDITION LEADERBOARD"<<endl;
    gotoxy(32,6);cout<<"RANK\t\tUSERNAME\tSCORE\t\tAVERAGE_SCORE\n";
    for (i=0;i<=marker;i++)
        {
            for (a = i+1; a<=marker; a++)
            {
                if (x[i].scoreA<x[a].scoreA)
                {
                    temp = x[i];
                    x[i] = x[a];
                    x[a] = temp;
                }
            }
            gotoxy(32,7+i);cout<<" "<<i+1<< "\t\t" << x[i].username << "\t\t  "<<x[i].scoreA<<"\t\t"<<fixed <<setprecision(2)<<(float) x[i].scoreA/item * 100 <<"%"<< endl;
        }
    gotoxy(44,21);system("pause");
}


void MyClass::subtract(string n)
{
    system("cls");
    int a, b, c;
    int i, p, temp;
    p = locate(n);

    int s_score = 0;
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

    srand (time(NULL));
    for (i=0;i<item;i++)
    {
        a = rand()% 10 + 1;
        b = rand()% 10 + 1;

        design();
        gotoxy(52,3);cout<<"SUBTRACTION GAME"<<endl;

        gotoxy(48,7);cout << i+1 << ".) " << a << " - " << b << " = ?\n";
        gotoxy(48,8);cout<<"Answer: ";
        cin >> c;
    if(c == a-b)
        {
        gotoxy(48,9);cout << "Your answer is";SetConsoleTextAttribute(h,10);cout<<" CORRECT!" << endl;
        s_score++;
        SetConsoleTextAttribute(h,7);
        gotoxy(48,10);system("pause");
        system("cls");
        design();
        }
    else {
            SetConsoleTextAttribute(h,12);
            gotoxy(48,10);cout << "WRONG ANSWER!"<<endl;
            SetConsoleTextAttribute(h,7);
            gotoxy(48,11);cout<< "CORRECT ANSWER: " << a - b << endl;
            gotoxy(48,13);system("pause");
            system("cls");
            design();
        }
    }
    gotoxy(48,10);cout << "Total Score: " << s_score << " out of " << item <<endl;
    gotoxy(48,11);cout<<"Average: " << (float) s_score/item * 100 <<"%"<<endl;
    gotoxy(48,13);system("pause");

    if (x[p].scoreS<= s_score)
    {
        temp = x[p].scoreS;
        x[p].scoreS = s_score;
        s_score = temp;
    }
    save_Ave(n);
    sublboard();
}


void MyClass::sublboard()
{
    int i,a;
    PREC temp;

    system("cls");
   design();
    gotoxy(52,2);cout<<"SUBSTRACTION LEADERBOARD"<<endl;
    gotoxy(32,6);cout<<"RANK\t\tUSERNAME\tSCORE\t\tAVERAGE_SCORE\n";
    for (i=0;i<=marker;i++)
        {
            for (a = i+1; a<=marker; a++)
            {
                if (x[i].scoreS<x[a].scoreS)
                {
                    temp = x[i];
                    x[i] =  x[a];
                    x[a] = temp;
                }
            }
            gotoxy(32,7+i);cout << " "<<i+1 <<"\t\t" << x[i].username << "\t\t   " <<x[i].scoreS<<"\t\t"<< (float) x[i].scoreS/item * 100 <<"%"<<endl;
        }
    gotoxy(44,21);system("pause");
}


void MyClass::multiply(string n)
{
    system("cls");
    int a, b, c;
    int i, p, temp;
    p = locate(n);

    int n = 0;
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

    srand (time(NULL));
    for (i=0;i<item;i++)
    {
        a = rand()% 10 + 1;
        b = rand()% 10 + 1;

        design();
        cout<<"MULTIPLICATION GAME\n"<<endl;

        cout << i+1 << ".) " << a << " x " << b << " = ?\n";
        cout<<"Answer: ";
        cin >> c;
    if(c == a*b)
        {
            cout << "Your answer is";SetConsoleTextAttribute(h,10);cout<<" CORRECT!" << endl;
            n++;
            SetConsoleTextAttribute(h,7);
            gotoxy(48,10);system("pause");
            system("cls");
        }
    else {
            SetConsoleTextAttribute(h,12);
            cout << "WRONG ANSWER!"<<endl;
            SetConsoleTextAttribute(h,7);
            cout<< "CORRECT ANSWER: " << a * b << endl;
            system("pause");
            system("cls");
        }
    }
        cout << "Total Score: " << n << " out of " << item <<endl;
        gotoxy(48,11);cout<<"Average: " << (float) m_score/item * 100 << endl;
        gotoxy(48,12);system("pause");

    if (x[p].scoreM<=m_score)
    {
        temp = x[p].scoreM;
        x[p].scoreM= m_score;
        m_score = temp;
    }
    save_Ave(n);
    mulboard();
}


void MyClass::mulboard()
{
    int i,a;
    PREC temp;

    system("cls");
    design();
    gotoxy(50,2);cout<<"MULTIPLICATION LEADERBOARD"<<endl;
    gotoxy(32,6);cout<<"RANK\t\tUSERNAME\tSCORE\t\tAVERAGE_SCORE\n";
    for (i=0;i<=marker;i++)
        {
            for (a = i+1; a<=marker; a++)
            {
                if (x[i].scoreM< x[a].scoreM)
                {
                    temp = x[i];
                    x[i] = x[a];
                    x[a] = temp;
                }
            }
         gotoxy(32,7+i);cout << " " << i+1 << "\t\t" << x[i].username <<"\t\t  "<<x[i].scoreM <<"\t\t"<<(float) x[i].scoreM/item * 100 <<"%"<< endl;
        }
    gotoxy(44,21);system("pause");
}


void MyClass::divide(string n)
{
    system("cls");
    int a, b, c, d;
    int i, p, temp;
    p = locate(n);

    int n = 0;
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

    srand (time(NULL));
    for (i=0;i<item;i++)
    {
        a = rand()% 10 + 1;
        b = rand()% 10 + 1;
    cout << i+1 << ".) " << a << " / " << b << " = ?\n";
    cout<<"Answer(quotient part): ";
    cin >> c;
    cout << "Answer(remainder part): ";
    cin >> d;
    if(c == a/b && d == a%b)
        {
        cout << "Your answer is";SetConsoleTextAttribute(h,10);cout<<" CORRECT!" << endl;
        n++;
        SetConsoleTextAttribute(h,7);
        system("pause");
        system("cls");
        }
    else {

        SetConsoleTextAttribute(h,12);
        cout << "WRONG ANSWER!"<<endl;
        SetConsoleTextAttribute(h,7);
        cout<< "CORRECT_ANSWER: "<< a/b <<endl;
        cout<<"(remainder): " << a%b << endl;
        system("pause");
        system("cls");
        }
    }
    cout << "Total Score: " << n << " out of " << item <<endl;
    gotoxy(48,11);cout<< "Average: " << (float) dv_score/item * 100 << endl;
    gotoxy(48,13);system("pause");

    if (x[p].scoreD<=dv_score)
    {
        temp = x[p].scoreD;
        x[p].scoreD = dv_score;
        dv_score = temp;
    }
    save_Ave(n);
    divlboard();
}


void MyClass::divlboard()
{
    int i,a;
    PREC temp;

    system("cls");
    design();
    gotoxy(52,2);cout<<"DIVISION LEADERBOARD"<<endl;
    gotoxy(32,6);cout<<"RANK\t\tUSERNAME\tSCORE\t\tAVERAGE_SCORE\n";
    for (i=0;i<=marker;i++)
        {
            for (a = i+1; a<=marker; a++)
            {
                if (x[i].scoreD< x[a].scoreD)
                {
                    temp = x[i];
                    x[i] = x[a];
                    x[a] = temp;
                }
            }
        gotoxy(32,7+i);cout << " " << i+1 << "\t\t" << x[i].username<< "\t\t  " <<x[i].scoreD << "\t\t" << (float) x[i].scoreD/item * 100 <<"%"<<endl;
        }
    gotoxy(44,21);system("pause");
}


void MyClass::overall()
{
    int i,a;
    PREC temp;

    system("cls");
    design();
    gotoxy(50,2);cout<<"OVERALL SCORE LEADERBOARD"<<endl;
    gotoxy(22,6);cout<<"RANK USERNAME  ADDITION  SUBTRACTION  MULTIPLICATION  DIVISION\tAVERAGE_SCORE\n";
    for (i=0;i<=marker;i++)
        {
            for (a = i+1; a<=marker; a++)
            {
                if (x[i].average<x[a].average)
                {
                    temp = x[i];
                    x[i] = x[a];
                    x[a] = temp;
                }
            }
            gotoxy(22,7+i);cout << " " << i+1<<setw(7)<< x[i].username <<setw(10)<<x[i].scoreA<<setw(12)<<x[i].scoreS<<setw(14)<<x[i].scoreM<<setw(14)<<x[i].scoreD<<setw(15)<<fixed<<setprecision(2)<<x[i].average <<"%"<<endl;
        }
    gotoxy(44,21);system ("pause");
}

int MyClass::login_lead_menu()
{
    int option;

    system("cls");
    design();

     gotoxy(48,2);cout << "ARITHMETIC GAME LEADERBOARDS\n";
     gotoxy(35,7);cout << "1. ADDITION RANKING\n";
     gotoxy(35,8);cout << "2. SUBTRACTION RANKING\n";
     gotoxy(35,9);cout << "3. MULTIPLICATION RANKING\n";
     gotoxy(35,10);cout << "4. DIVISION RANKING\n";
     gotoxy(35,11);cout << "5. OVERALL RANKING\n";
     gotoxy(35,12);cout << "6. BACK\n";
     gotoxy(35,13);cout << "7. EXIT PROGRAM\n\n";

     gotoxy(35,15);cout << "Enter number: ";
    cin >> option;
    return (option);
}

void MyClass::login_leaderboards()
{
    while (1)
    {
        switch (login_lead_menu())
        {
            case 1 : addlboard(); break;
            case 2 : sublboard(); break;
            case 3 : mulboard(); break;
            case 4 : divlboard(); break;
            case 5 : overall(); break;
            case 6 : act_login(); break;
            case 7 : exit (0); break;
            default: gotoxy(33,17);cout << "choose from 1-7 only" << endl;
                     gotoxy(33,18);system("pause"); break;
        }
    }
}

int MyClass::ingame_lead_menu()
{
    int option;

    system("cls");
    design();

     gotoxy(48,2);cout << "ARITHMETIC GAME LEADERBOARDS";
     gotoxy(35,7);cout << "1. ADDITION RANKING";
     gotoxy(35,8);cout << "2. SUBTRACTION RANKING";
     gotoxy(35,9);cout << "3. MULTIPLICATION RANKING";
     gotoxy(35,10);cout <<"4. DIVISION RANKING";
     gotoxy(35,11);cout <<"5. OVERALL RANKING";
     gotoxy(35,12);cout <<"6. BACK";
     gotoxy(35,13);cout <<"7. EXIT";

     gotoxy(35,15);cout << "Enter number: ";
     cin >> option;
    return (option);
}

void MyClass::ingame_leaderboards(string n)
{
    while (1)
    {
        switch (ingame_lead_menu())
        {
            case 1 : addlboard(); break;
            case 2 : sublboard(); break;
            case 3 : mulboard(); break;
            case 4 : divlboard(); break;
            case 5 : overall(); break;
            case 6 : arithmetic_game(n); break;
            case 7 : save(); exit (0); break;
            default: gotoxy(33,17);cout << "choose from 1-7 only" << endl;
                    gotoxy(33,18);system("pause"); break;
        }
    }
}

void MyClass::save_Ave(string n)
{
    int p = locate(n);
    float current_ave, temp;

    current_ave = ave(x[p].scoreA,x[p].scoreS,x[p].scoreM,x[p].scoreD)*100;


    if (x[p].average<current_ave)
    {
        temp = x[p].average;
        x[p].average = current_ave;
        current_ave = temp;
    }
}


int MyClass::login_menu()
{
    int option;
    system("cls");
    design();

    gotoxy(55,2);cout << " ACCOUNT MENU ";
    gotoxy(53,8);cout << "1. CREATE ACCOUNT ";
    gotoxy(53,9); cout << "2. LOG IN";
    gotoxy(53,10);cout << "3. LEADERBOARDS ";
    gotoxy(53,11);cout << "4. EXIT & SAVE";
    gotoxy(53,13);cout << "Select(1-4): ";
    cin >> option;
    return(option);
}


void MyClass::act_login()
{
    while (1)
    {
        switch(login_menu())
        {
            case 1 : create_acc(); break;
            case 2 : login(); break;
            case 3 : login_leaderboards(); break;
            case 4 : save(); exit (0);
            default: gotoxy(53,15);cout << "please choose from numbers 1-4 only....\n" << endl;
                     gotoxy(53,16);system("pause"); break;
        }
    }
}


int MyClass::menu()
{
    system("cls");
    int i,option;

    design();
    string mode [100]={"ADDITION GAME","SUBTRACION GAME","MULTIPLICATION GAME","DIVISION GAME","LEADERBOARDS","ACCOUNT MENU","EXIT & SAVE"};

    system("cls");
    design();
    gotoxy(55,2);cout << "ARITHMETIC GAME" << endl;
    for (i=0;i<7;i++){
        gotoxy(35,7+i);
            cout << i+1 << ".) " << mode[i];
    }
    gotoxy(36,8+i);
        cout << "Select(1-7): ";
        cin >> option;
    return(option);
}


void MyClass::arithmetic_game(string n)
{
    int d;
    while(1) {
        switch(menu()){
            case 1 : add(n); break;
            case 2 : subtract(n); break;
            case 3 : multiply(n); break;
            case 4 : divide(n); break;
            case 5 : ingame_leaderboards(n); break;
            case 6 : act_login(); break;
            case 7 : save(); exit (0);
            default: gotoxy(36,15); cout << "Please choose from numbers 1-7 only....";
                     gotoxy(36,17); system("pause"); break;
        }
    }
}


float MyClass::ave (int a, int s, int d, int m)
{
    return((float) (a+s+d+m)/4 /item);
}

int MyClass::locate(string n)
{
    int i;
    for (i=0;i<=marker;i++)
    if (x[i].username==n)
    {
        return i;
    }
        return -1;
}

int MyClass::compare(string user, string pass)
{
    int i;
    for (i=0;i<=marker;i++)
    if (x[i].username==user && x[i].password==pass)
    {
      return 0;
    }
      return -1;
}

void MyClass::add_rec(string n, string p, int a, int s, int m, int d, float av)
{
    marker++;
    x[marker].username = n;
    x[marker].password= p;
    x[marker].scoreA = a;
    x[marker].scoreS = s;
    x[marker].scoreM = m;
    x[marker].scoreD = d;
    x[marker].average = av;
}

void MyClass::retrieve()
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    fstream fp;
    fp.open("account_data.txt",ios::in);


        string usrnm;
        string pss;
        int scoreA, scoreS,scoreM,scoreD;
        float grades;

    if (!fp){
        SetConsoleTextAttribute(h,12);
        gotoxy(44,10);cout << "No data to retrieved." << endl;
        SetConsoleTextAttribute(h,7);
         gotoxy(44,12);system("pause");
    }

    else {
    while(true)
    {
        fp >> usrnm;
        fp >> pss;
        fp >> scoreA;
        fp >> scoreS;
        fp >> scoreM;
        fp >> scoreD;
        fp >> grades;

        if (!fp.eof())
            add_rec(usrnm,pss,scoreA,scoreS,scoreM,scoreD,grades);
        else
            break;

        gotoxy(44,10);SetConsoleTextAttribute(h,10);cout << "Account has been retrieved! "<<endl;
        SetConsoleTextAttribute(h,7);
    }
    gotoxy(44,12);system("pause");
    }
        fp.close();
}

void MyClass::save()
{
    fstream fp;
    int i;
    float overall;

    fp.open("account_data.txt",ios::out);

    if (!fp){
        cout << "File error. . ." << endl;
        fp.close();
        system("pause");
    }

    else {
    for (i=0;i<=marker;i++)
        {
        overall = ave(x[i].scoreA,x[i].scoreS,x[i].scoreM,x[i].scoreD);
        fp << x[i].username << "\t" << x[i].password << "\t" << x[i].scoreA<< "\t" << x[i].scoreS << "\t" << x[i].scoreM<< "\t" << x[i].scoreD << "\t" << overall*100 << endl;
        }
    }
        fp.close();
}

int main()
{
    MyClass face;
    marker = -1;
    face.retrieve();
    system("cls");
    face.act_login();
    return 0;
}

void MyClass::gotoxy(int x,int y)
{
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void MyClass::design(){
    int i;
    int r;


    for(i=21; i<=100;++i)
    {
        gotoxy(i,0);
        cout<<"*";
    }
    for(r=1; r<=25;++r)
    {
        gotoxy(101,r);
        cout<<"*";

    }
    for(i=100; i>=20;--i)
    {
        gotoxy(i,20);
        cout<<"*";

    }
    for(r=25; r>=1;--r)
    {
        gotoxy(20,r);
        cout<<"*";
    }
    return;
}
void MyClass::design2()
{
    int i;
    int r;


    for(i=51; i<=70;++i)
    {
        gotoxy(i,10);
        cout<<"_";
    }
    for(r=11; r<=13;++r)
    {
        gotoxy(71,r);
        cout<<"|";

    }
    for(i=70; i>=50;--i)
    {
        gotoxy(i,13);
        cout<<"_";
    }
    for(r=13; r>=11;--r)
    {
        gotoxy(50,r);
        cout<<"|";
    }

    return;
}
COORD coord = {0, 0};
