//John Lawrence H. Castillejo     
//BSIT-2AB-M
//11-16-2022
                                            /*PRELIM EXAM*/

//No. 1 - Write the function insert(string name)that inserts a unique Student Record using name as key in a sorted listusing array of structuresADT List.
#include <iostream>
#include <string>
using namespace std;

s#include <iostream>
#include <string>
using namespace std;

struct StudentRecord
{
    string name;
    int q1, q2, q3;
};

void insert(StudentRecord list[], int &size, string name)
{
    int i = 0;
    while (i < size && list[i].name < name)
        i++;
    if (i < size && list[i].name == name)
        return;
    for (int j = size; j > i; j--)
        list[j] = list[j - 1];
    list[i].name = name;
    size++;
}

int main()
{
    StudentRecord list[100];
    int size = 0;
    insert(list, size, "John");
    insert(list, size, "Mary");
    insert(list, size, "Mary");
    insert(list, size, "Peter");
    insert(list, size, "Mary");
    insert(list, size, "John");
    insert(list, size, "Mary");
    insert(list, size, "Mary");
    insert(list, size, "Peter");
    insert(list, size, "Mary");
    for (int i = 0; i < size; i++)
        cout << list[i].name << endl;
    return 0;
}


//No. 2 - Write the function insert(string name)that inserts a unique Student Record using name as key in a sorted listusing pointer implementation of ADT List.
#include <iostream>
#include <string>
using namespace std;

class StudentRecord
{
public:
    string name;
    int q1, q2, q3;
    StudentRecord *next;
    StudentRecord(string name, int q1, int q2, int q3)
    {
        this->name = name;
        this->q1 = q1;
        this->q2 = q2;
        this->q3 = q3;
        next = NULL;
    }
};

class List
{
public:
    StudentRecord *head;
    List()
    {
        head = NULL;
    }

void insert(string name, int q1, int q2, int q3)
    {
        StudentRecord *newRecord = new StudentRecord(name, q1, q2, q3);
        if (head == NULL)
        {
            head = newRecord;
            return;
        }
        if (head->name > name)
        {
            newRecord->next = head;
            head = newRecord;
            return;
        }
        StudentRecord *temp = head;
        while (temp->next != NULL && temp->next->name < name)
        {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->name == name)
        {
            cout << "Name already exists" << endl;
            return;
        }
        newRecord->next = temp->next;
        temp->next = newRecord;
    }

void print()
    {
        StudentRecord *temp = head;
        while (temp != NULL)
        {
            cout << temp->name << " " << temp->q1 << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    List list;
    list.insert("A", 1, 2, 3);
    list.insert("B", 1, 2, 3);
    list.insert("C", 1, 2, 3);
    list.insert("D", 1, 2, 3);
    list.insert("E", 1, 2, 3);
    list.insert("F", 1, 2, 3);
    list.insert("G", 1, 2, 3);
    list.insert("H", 1, 2, 3);
    list.insert("I", 1, 2, 3);
    list.insert("J", 1, 2, 3);
    list.insert("K", 1, 2, 3);
    list.insert("L", 1, 2, 3);
    list.insert("M", 1, 2, 3);
    list.insert("N", 1, 2, 3);
    list.insert("O", 1, 2, 3);
    list.insert("P", 1, 2, 3);
    list.insert("Q", 1, 2, 3);
    list.insert("R", 1, 2, 3);
    list.insert("S", 1, 2, 3);
    list.insert("T", 1, 2, 3);
    list.insert("U", 1, 2, 3);
    list.insert("V", 1, 2, 3);
    list.insert("W", 1, 2, 3);
    list.insert("X", 1, 2, 3);
    list.insert("Y", 1, 2, 3);
    list.insert("Z", 1, 2, 3);
    list.print();
    return 0;
}


//No. 3 - Write the function update(string name) that updates a Student Record using arrayof structures implementation of ADT List.
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int q1, q2, q3;
};

class List
{
    Student *s;
    int size;
    int count;
public:
    List(int n)
    {
        size = n;
        count = 0;
        s = new Student[size];
    }

void update(string name){
    int i;
    for(i=0;i<count;i++){
        if(s[i].name==name)
        {
            cout<<"Enter the new marks of the student"<<endl;
            cin>>s[i].q1>>s[i].q2>>s[i].q3;
            break;
        }
    }
        if(i==count)
        {
            cout<<"Student not found"<<endl;
        }
}
    

//No. 4 - Write function enqueue(int x) in a pointer implementation of Queue of Integers.
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Queue{
    Node *front;
    Node *rear;
    public:
    Queue(){
        front = NULL;
        rear = NULL;
    }
    void enqueue(int x);
};

void Queue::enqueue(int x){
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL){
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}


//No. 5 - Write function pop() in a pointer implementation of Stack of Integers.
#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;
public:
    Stack(int size = 100) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    ~Stack() {
        delete arr;
    }
    
int pop() {
    if (isEmpty()) {
        cout << "UnderFlow" << endl;
        exit(EXIT_FAILURE);
        }
    cout << "Removing " << peek() << endl;
    return arr[top--];
}


//No. 6 - Write function display() inan array implementation of Queue of integers.
#include <iostream>
using namespace std;

class Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
public:
void display() {
        int i;
        if (isEmpty(this))
            return;
        cout << "Elements in Circular Queue are: ";
        for (i = front; i != rear; i = (i + 1) % capacity)
            cout << array[i] << " ";
        cout << array[i];
        cout << endl;
        }
};


//No. 7 - Write function dequeue() in an array implementation of Queue of Integers.
#include <iostream>
using namespace std;
class Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
public:
    int dequeue()
    {
        if (isEmpty(this))
            return INT_MIN;
        int item = this->array[this->front];
        this->front = (this->front + 1) % this->capacity;
        this->size = this->size - 1;
        return item;
    }
};


//No. 8 - Write function merge (L1,L2) that merges L2 into L1. L1 and L2 are two sorted Link Lists of Student Records.
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int q1,q2,q3;
    Student *next;
};

void merge(Student *&head1, Student *&head2)
{
    Student *temp1 = head1;
    Student *temp2 = head2;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->name < temp2->name)
        {
            temp1 = temp1->next;
        }
        else if(temp1->name > temp2->name)
        {
            Student *temp = temp2;
            temp2 = temp2->next;
            temp->next = temp1;
            if(temp1 == head1)
            {
                head1 = temp;
            }
            else
            {
                Student *temp3 = head1;
                while(temp3->next != temp1)
                {
                    temp3 = temp3->next;
                }
                temp3->next = temp;
            }
        }
        else
        {
            temp1->q1 = temp2->q1;
            temp1->q2 = temp2->q2;
            temp1->q3 = temp2->q3;
            temp1 = temp1->next;
            Student *temp = temp2;
            temp2 = temp2->next;
            delete temp;
        }
    }
    if(temp2 != NULL)
    {
        temp1->next = temp2;
    }
}


//No. 9 - Write function purge() that deletes replicate records in a Link List of student records.
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int q1, q2, q3;
    Student *next;
};

void purge(Student *&head)
{
    Student *temp = head;
    while (temp != NULL)
    {
        Student *temp2 = temp;
        while (temp2->next != NULL)
        {
            if (temp->name == temp2->next->name)
            {
                Student *temp3 = temp2->next;
                temp2->next = temp2->next->next;
                delete temp3;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}


//No. 10 - Write function withdraw(float amount,float balance) that checksif a given amount is a valid in an ATM Withdraw transaction.
#include <iostream>
using namespace std;

bool withdraw(float amount, float balance)
{
    if (amount > balance)
    {
        return false;
    }
    else if (amount > 1000)
    {
        return false;
    }
    else if (amount % 5 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}