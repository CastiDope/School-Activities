//Text File Compression & Decompression Project using Huffman Algorithm in our subject Data Structures and Algorithms
//Made by: John Lawrence H. Castillejo & Andre Vincent Gomez

//Libraries used
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>

using namespace std;

//Struct for the tree
struct Node {
    char letter;
    int count;
    Node *left;
    Node *right;
};

//Struct for comparing the frequency of the letters
struct compare {
    bool operator()(const Node *l, const Node *r) const {
        return (l->count > r->count);
    }
};

//Function to build the frequency table
void buildFrequencyTable(map<char, int> &table, string filename) {
    ifstream inFile;
    inFile.open(filename);
    char c;
    //while loop to read the text file
    while (inFile >> noskipws >> c) { 
        if (table.find(c) == table.end()) { //finds the letter in the table
            table[c] = 1;
        } else {
            table[c]++; //counts the frequency of the letters
        }
    }
    inFile.close();
}

//Function to build the tree
void buildTree(priority_queue<Node *, vector<Node *>, compare> &pq, map<char, int> table) {
    for (auto it = table.begin(); it != table.end(); it++) { //iterates through the table
        Node *n = new Node;
        n->letter = it->first;
        n->count = it->second;
        n->left = NULL;
        n->right = NULL;
        pq.push(n);
    }
}

//Function to build the Huffman Tree to compress the text file
void buildHuffmanTree(priority_queue<Node *, vector<Node *>, compare> &pq) {
    while (pq.size() > 1) {
        Node *n = new Node;
        n->letter = ' '; //empty character
        n->count = pq.top()->count; //counts the frequency of the letters
        n->left = pq.top(); 
        pq.pop(); //pops the top of the priority queue
        n->count += pq.top()->count; 
        n->right = pq.top();
        pq.pop();
        pq.push(n); //pushes the node to the priority queue
    }
}

//Function to build the code table for the letters
void buildCodeTable(map<char, string> &table, Node *root, string code) {
    if (root->left == NULL && root->right == NULL) {  //checks if the node is a leaf
        table[root->letter] = code;
    } else {    //if not a leaf, it will go to the left and right of the tree
        buildCodeTable(table, root->left, code + "0");
        buildCodeTable(table, root->right, code + "1");
    }
}

//Function to compress the text file
void compress(string filename, map<char, string> table) {
    ifstream inFile;
    inFile.open(filename);
    ofstream outFile;
    outFile.open("compressed.txt"); //creates a new text file for the compressed text file
    char c;
    //while loop to read the text file
    while (inFile >> noskipws >> c) { //noskipws is used to read the spaces
        outFile << table[c]; //writes the compressed text file
    }
    //closes the inputted file and the compressed text file
    inFile.close();
    outFile.close();
}

//Function to decompress the compressed text file
void decompress(string filename, Node *root) {
    ifstream inFile;
    inFile.open(filename);
    ofstream outFile;
    outFile.open("decompressed.txt"); //creates a new text file for the decompressed text file
    char c;
    Node *n = root;
    //While loop to read the compressed text file
    while (inFile >> noskipws >> c) {
        if (c == '0') {
            n = n->left;
        } else {
            n = n->right;
        }
        if (n->left == NULL && n->right == NULL) {
            outFile << n->letter;
            n = root;
        }
    }
    //closes compressed and decompressed text files
    inFile.close();
    outFile.close();
}



//Main function to compress  any text file and ask to decompress it or not
int main() {
    string filename;
    system("cls");
    cout << "Enter the name of the text file you want to compress: ";
    cin >> filename;
    map<char, int> table;
    buildFrequencyTable(table, filename); 
    priority_queue<Node *, vector<Node *>, compare> pq; 
    buildTree(pq, table);
    buildHuffmanTree(pq);
    map<char, string> codeTable;
    buildCodeTable(codeTable, pq.top(), "");
    compress(filename, codeTable); 
    cout << "Compressed!" << endl;
    //Show size after compression
    ifstream inFile;
    inFile.open("compressed.txt");
    inFile.seekg(0, ios::end);
    int size = inFile.tellg();
    cout << "Size of compressed file: " << size << " bytes" << endl;
    inFile.close();
    ifstream inFile2;
    inFile2.open(filename);
    inFile2.seekg(0, ios::end);
    int size2 = inFile2.tellg();
    cout << "Size of original file: " << size2 << " bytes" << endl;
    inFile2.close();
    system("pause");
    system("cls");
    cout << "Do you want to decompress the compressed file? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        decompress("compressed.txt", pq.top());
        cout << "Decompressed!" << endl;
        //Show size after decompression
        ifstream inFile;
        inFile.open("compressed.txt");
        inFile.seekg(0, ios::end);
        int size = inFile.tellg();
        cout << "Size of compressed file: " << size << " bytes" << endl;
        inFile.close();
        ifstream inFile2;
        inFile2.open("decompressed.txt");
        inFile2.seekg(0, ios::end);
        int size2 = inFile2.tellg();
        cout << "Size of decompressed file: " << size2 << " bytes" << endl;
        inFile2.close();
    }
    else {
        cout << "You decided not to decompress." << endl;
        system("pause");
    }
    //Loop choice if user wants to compress again
    system("cls");
    char choice2;
    cout << "Do you want to compress another file? (y/n): ";
    cin >> choice2;
    if (choice2 == 'y') {
        system("pause");
        system("cls");
        main();
    }
    else {
        cout << "You decided not to compress another file." << endl;
        cout << "Thank you for using this program!" << endl;
    }
    return 0;
}