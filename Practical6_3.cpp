#include<iostream>
using namespace std;

int main()
{
    int n,m;

    // Get the size of the first array
    cout<<"Enter the size of first array: "<<endl;
    cin>>n;

    // Get the size of the second array
    cout<<"Enter the size of second array: "<<endl;
    cin>>m;

    // Dynamically allocate memory for both arrays
    int* arr1 = new int[n];
    int* arr2 = new int[m];

    cout<<"Enter frist sorted array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter Second sorted array: "<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }

    // Allocate memory for the merged array
    int* merged = new int[n+m];

    int i=0,j=0,k=0;

    // Merge the arrays using two-pointer technique
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            merged[k++] =  arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }

    // If any elements are left in arr1, add them
    while(i<n)
    {
        merged[k++] =  arr1[i++];
    }
    // If any elements are left in arr2, add them
    while(j<m)
    {
        merged[k++] = arr2[j++];
    }

    cout<<"Mearged sorted array: "<<endl;
    for(int i=0;i<n+m;i++)
    {
        cout<<merged[i]<<" , ";
    }
    cout<<endl;

    // Free the dynamically allocated memory
    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
