#include<iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    string paragraph;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);    

    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);

    stringstream ss(paragraph);
    string words;
    vector<string> word;

    while (ss >> words)
    {
        word.push_back(words);
    }

    map<string, int> frequancy;
    for (const string w : word)
    {
        frequancy[w]++;
    }
    cout << "Word frequance: " << endl;
    for (const auto &pair : frequancy)
    {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}