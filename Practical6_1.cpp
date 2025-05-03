#include<iostream>
using namespace std;

class dynamicarray
{
    int* data;
    int capacity;
    int size;

    void resize()
    {
        cout<<"Resize function called: ";
        capacity *= 2; // Double the capacity
        int* new_data = new int[capacity]; // Allocate new array
        for(int i=0; i<size; i++)
        {
            new_data[i] = data[i];
        }
        delete [] data;  // Free old memory
        data = new_data; // Point to new array
    }
public:
    dynamicarray(int initial_capacity = 4)
    {
        size = 0;
        capacity = initial_capacity;
        data = new int[capacity]; // Allocate initial memory
    }
    ~dynamicarray() // Destructor
    {
        delete [] data;
    }

    // Insert a value at the end of the array
    void insert(int value)
    {
        if(size == capacity)
        {
            resize(); // Resize if array is full
        }
        data[size++] = value; // Resize if array is full
    }

    // Remove element at specified index
    void remove(int index)
    {
        if(index <0 || index >= size)
        {
            cout<<"Invalid index\n";
            return;
        }
        for(int i = index; i<size-1; i++)
        {
            data[i] = data[i+1];
        }
        size--; // Decrease the size
    }
    int get(int index) const
    {
        if(index <0 || index >= size)
        {
            cout<<"Invalid index\n";
            return -1;
        }
        else
        {
            return data[index];
        }
    }
    int get_size() const // Return current size of the array
    {
        return size;
    }
    int get_capacity() const
    {
        return capacity;
    }

    void print_data() const
    {
        cout<<"The values of the array is: "<<endl;
        for(int i=0; i<size; i++)
        {
            cout<<data[i]<<", ";
        }
    }
};

int main()
{
    dynamicarray arr; // Create a dynamic array object

    // Insert elements
    arr.insert(7);
    arr.insert(45);
    arr.insert(8);
    arr.insert(18);
    arr.print_data();

    // Get and display element at index 3
    cout<<"Element at index 3: "<<arr.get(3)<<endl;
    // Remove element at index 3
    arr.remove(3);

    arr.insert(99);
    arr.insert(31);
    arr.print_data();
    cout<<"Element at index 3: "<<arr.get(3)<<endl;

    // Show size and capacity
    cout<<"Size: "<<arr.get_size()<<endl;
    cout<<"Capacity: "<<arr.get_capacity()<<endl;

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}