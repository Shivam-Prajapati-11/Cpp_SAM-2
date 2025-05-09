#include <iostream>
#include <set>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    int n, id;


    set<int> transactionIDs;

    cout << "Enter number of transaction IDs: ";
    cin >> n;

    cout << "Enter transaction IDs:\n";
    for (int i = 0; i < n; ++i) {
        cin >> id;
        transactionIDs.insert(id);
    }


    cout << "\nUnique and Sorted Transaction IDs:\n";
    for (set<int>::iterator it = transactionIDs.begin(); it != transactionIDs.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    vector<int> uniqueIDs(transactionIDs.begin(), transactionIDs.end());

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}