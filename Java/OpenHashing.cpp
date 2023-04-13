//An open hashing program to insert, search, display and delete a key.

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

struct node //node structure
{
    int data;
    struct node *next;
};
struct node *head[10];

void insert(int key) //inserting a key
{
    int index = key % 10;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    if (head[index] == NULL) //If function to check if the head is empty or not
    {
        head[index] = temp;
        cout << "Key << " << key << " >> has been inserted" << endl;
        system("pause");
    }
    else
    {
        struct node *p = head[index];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    system("cls");
}

void search(int key) //searching for a key
{
    int index = key % 10;
    struct node *p = head[index];
    while (p != NULL) //While function to check if the key is found or not
    {
        if (p->data == key)
        {
            cout << "Key " << key << " has been found" << endl;
            system("pause");
            return;
        }
        p = p->next;
    }
    cout << "Key not found" << endl;
    system("cls");
}

void deleteKey(int key) //deleting a key
{
    int index = key % 10;
    struct node *p = head[index];
    struct node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            if (q == NULL)
            {
                head[index] = p->next;
            }
            else
            {
                q->next = p->next;
            }
            free(p);
            cout << "Key " << key << " has been deleted" << endl;
            system("pause");
            return;
            
        }
        q = p;
        p = p->next;
    }
    cout << "Key not found" << endl;
    system("cls");
}

void display() //displaying the hash table
{
    for (int i = 0; i < 10; i++)
    {
        struct node *p = head[i];
        cout << i << " : ";
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    int choice, key;
    while (1)
    {
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            cout << "Enter the key to insert: ";
            cin >> key;
            insert(key);
            system("cls");
            break;
        case 2:
            cout << "Enter the key to search: ";
            cin >> key;
            search(key);
            system("cls");
            break;
        case 3:
            cout << "Enter the key to delete: ";
            cin >> key;
            deleteKey(key);
            system("cls");
            break;
        case 4:
            display();
            system("pause");
            system("cls");
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            system("cls");
        }
    }
    system("cls");
    return 0;
}