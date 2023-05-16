#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ifstream file("charfreq.txt");
    string str;
    map<char, int> freq;
    while (getline(file, str))
    {
        for (int i = 0; i < str.length(); i++)
        {
            freq[str[i]]++;
        }
    }
    for (auto i : freq)
    {
        cout <<"Character [" << i.first << "] frequency is " << i.second << endl;
    }
    return 0;
}

