/*A technology firm aimed to develop a flexible and reusable solution for managing collections of various
data types, including integers, floating-point numbers, and characters. The system was intended to
perform fundamental operations on these collections, such as finding the maximum value, reversing
the collection, and displaying all elements. To achieve versatility and avoid redundancy in code, the
solution was designed to use function templates, allowing the same logic to be applied seamlessly to
different data types.
The team recognized the importance of using dynamic arrays to store the collections, enabling
efficient management of varying collection sizes. The design emphasized scalability and flexibility,
ensuring that the system could handle different data types and their associated operations with
minimal changes to the core logic.
In practice, the system allowed for the creation of collections for various data types, such as integers,
floating-point numbers, and characters. The operations on these collections included determining the
maximum value, reversing the order of elements, and printing the collection contents.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> // Template function that find the maximum value in a vector
T findmax(const vector<T> &vec)
{
    T maxVal = vec[0];
    for (const auto &elem : vec)
    {
        if (elem > maxVal)
        {
            maxVal = elem;
        }
    }
    return maxVal;
}

template <typename T> // Template function that reverse a vector
void reversevac(vector<T> &vec)
{
    reverse(vec.begin(), vec.end());
}

template <typename T> // Template function that display the contents of a vector
void displayvector(const vector<T> &vec)
{
    for (const auto &elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    // --------------------Integer vector-----------------------------
    vector<int> intvac = {1, 20, 3, 4, 5};
    cout << "Integer Vector: ";
    displayvector(intvac);
    
    cout << "Maximum integer vector: " << findmax(intvac) << endl;
    reversevac(intvac);
    
    cout << "Reversed Integer Vector: ";
    displayvector(intvac);

    // --------------------Double vector------------------------------
    vector<double> doublevac = {9.8, 9.9, 1.18};
    cout << endl
         << "Double Vector: ";
    
    displayvector(doublevac);
    
    cout << "Maximum double vector: " << findmax(doublevac) << endl;
    reversevac(doublevac);
    
    cout << "Reversed Double Vector: ";
    displayvector(doublevac);

    // -------------------Character vector----------------------------
    vector<char> charvac = {'s', 'h', 'i', 'v', 'a', 'm'};
    
    cout << endl
         << "Character Vector: ";
    
    displayvector(charvac);
    
    cout << "Maximum character vector: " << findmax(charvac) << endl;
    reversevac(charvac);
    
    cout << "Reversed Character Vector: ";
    displayvector(charvac);

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
