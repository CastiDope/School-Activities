//Text File Compression Project using Huffman Algorithm in Data Structures and Algorithms
//Made by: John Lawrence H. Castillejo & Andre Vincent Gomez

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
    if (root->left == NULL && root->right == NULL) { 
        table[root->letter] = code;
    } else {
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
    inFile.close();
    outFile.close();
}

//Main function to compress and any text file and ask to decompress or not
int main() {
    string filename;
    system("cls");
    cout << "Enter the name of the file: ";
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
    cout << "Do you want to decompress the compressed file? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        decompress("compressed.txt", pq.top());
        cout << "Decompressed!" << endl;
    }
    else {
        cout << "You decided not to decompress." << endl;
    }
    return 0;
}