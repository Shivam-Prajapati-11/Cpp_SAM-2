/*A data analytics company was tasked with developing a unique digital signature system based on the
concept of "super digits." The system required finding a single-digit representation of a given number
through recursive digit summation. The algorithm was defined as follows:
If the number has only one digit, it is its super digit. Otherwise, the super digit is the super digit of the
sum of its digits, repeated recursively until a single digit is obtained.
The challenge involved an additional complexity—constructing the number by concatenating a given
string representation of an integer multiple times. For example, if the number n was represented as a
string and concatenated k times, the super digit of the resulting number needed to be calculated.
For instance:
Given n = 9875 and k = 4, the number is represented as 9875987598759875.
The sum of digits in this number is calculated recursively until a single digit remains:
9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 = 116
1 + 1 + 6 = 8
The super digit is 8.
The system was required to handle large numbers efficiently by leveraging mathematical insights
rather than explicitly constructing large concatenated strings. This case study called for implementing
a recursive solution to calculate the super digit, supported by a mathematical approach to optimize
the handling of repeated sums.*/

#include<iostream>
#include <string>
using namespace std;

// Function to compute the super digit
int superDigit(string n, int k)
{
    // Calculate the sum of the digits of n
    long long sum = 0;
    for (char digit : n)
    {
        sum += digit - '0'; // Convert char to integer and add to sum
    }
    sum *= k;

    if (sum < 10)    // Recursively calculate the super digit
    {
        // Base case: If the sum is a single digit, return it
        return sum; 
    }
    else
    {
        // Convert the sum to string and recursively find the super digit
        return superDigit(to_string(sum), 1); // Only call recursively once
    }
    cout<<sum<<endl;
}

int main()
{
    string n;
    int k;

    // Read input for n and k
    cout<<"Enter number: ";
    cin>>n;

    cout<<"Enter repetation factor k: ";
    cin>>k;

    // Print the result
    int result = superDigit(n, k);
    cout << "Super Digit: " << result << endl;

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
