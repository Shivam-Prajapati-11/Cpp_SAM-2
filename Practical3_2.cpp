/*A software development company was tasked with conducting a performance analysis of recursive
algorithms versus their iterative counterparts. The specific focus was on calculating the sum of
integers in an array, where the array's size and elements were to be provided dynamically by the user.
To facilitate memory management and enable dynamic resizing of the array, the team decided to use
a flexible container for storing the array elements.
The system was designed to first prompt users for the array's size and then request the input of
individual elements. A recursive function was to be implemented to compute the sum by dividing the
problem into smaller sub-problems, recursively summing subsets of the array until reaching the base

case. In addition to the recursive implementation, an iterative version of the function would be
created for comparison.
The main objective of the study was to assess and compare the computational performance and
implementation complexity of both recursive and non-recursive approaches. By evaluating execution
times, memory usage, and code complexity, the team hoped to gain insights into the trade-offs
between recursion and iteration, particularly in terms of efficiency and applicability to real-world
problems.*/

#include <iostream>
#include <vector>
using namespace std;

int recursive_sum(vector<int> &array, int n) //Recursive function that calculate the sum of array elements 
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return array[n-1] + recursive_sum(array, n-1);
    }
}
int iterative_sum(const vector<int>& array) // Iterative function that calculate the sum of array elements
{
    int s = 0;
    for(auto& i : array)
    {
        s += i;
    }
    return s;
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> array(n); //Vector that dinamically hold the elements

    for (int i = 0; i < n; ++i) //Enter input from the user
    {
        cout << "Enter Element " << i + 1 << ": ";
        cin >> array[i];
    }
    //Both recursive and iterative approaches
    int recursivesum = recursive_sum(array, n);
    int iterativesum = iterative_sum(array);
    
    cout<<endl;
    cout << "Recursive sum is " << recursivesum << endl;
    cout << "Iterative sum is " << iterativesum << endl;

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
