//A close hashing program to insert, search, display and delete a key.

#include <iostream>
#include <stdlib.h>
using namespace std;

class HashTable //class for hash table
{
    int *arr;
    int size;
    int count;

public:
    HashTable(int size) //constructor
    {
        this->size = size;
        arr = new int[size];
        count = 0;
        for (int i = 0; i < size; i++)
            arr[i] = -1;
    }

    int hash(int key) //fuction to hash the key
    {
        return key % size; 
    }

    void insert(int key) //function to insert a key
    {
        if (count == size)
        {
            cout << "Hash Table is full" << endl;
            system("pause");
            return;
        }
        int index = hash(key); //hashing the key
        while (arr[index] != -1 && arr[index] != -2 && arr[index] != key) //While function to check if the key is already present or not
        {
            index = (index + 1) % size;
        }
        if (arr[index] == key)
        {
            cout << "Element " << key << " already exists" << endl;
            system("pause");
        }
        else
        {
            arr[index] = key;
            cout << "Element "<< key << " has been inserted" << endl;
            system("pause");
            count++;
        }
    }

    void remove(int key) //function to remove a key
    {
        int index = hash(key);
        while (arr[index] != -1) //While function to check if the key is found to delete or not found
        {
            if (arr[index] == key)
            {
                arr[index] = -2;
                count--;
                cout << "Element " << key << " has been deleted" << endl;
                system("pause");
                return;
            }
            index = (index + 1) % size;
        }
        cout << "Element "<< key << " is not found" << endl;
        system("pause");
    }

    void search(int key) //function to search a key
    {
        int index = hash(key);
        while (arr[index] != -1)//While function to check if the key is found or not
        {
            if (arr[index] == key)
            {
                cout << "Element " << key << " is found" << endl;
                system("pause");
                return;
            }
            index = (index + 1) % size;
        }
        cout << "Element " << key << " is not found" << endl;
        system("pause");
    }

    void display() //function to display the hash table
    {
        for (int i = 0; i < size; i++) //for loop to display the hash table
        {
            if (arr[i] != -1 && arr[i] != -2)
                cout << i << " --> " << arr[i] << endl;
        }
        system("pause");
    }
};

int main() //main menu function
{
    int choice, key;
    HashTable h(10);
    system("cls");
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
            h.insert(key);
            system("cls");
            break;
        case 2:
            cout << "Enter the key to search: ";
            cin >> key;
            h.search(key);
            system("cls");
            break;
        case 3:
            cout << "Enter the key to delete: ";
            cin >> key;
            h.remove(key);
            system("cls");
            break;
        case 4:
            h.display();
            system("cls");
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            system("pause");
            system("cls");
        }
    }
    return 0;
}

