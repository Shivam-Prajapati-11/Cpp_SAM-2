#include <iostream>
using namespace std;

class person // Create base class named person
{
protected:
    string name;
    int age;

public:
    person(string n, int a) : name(n), age(a) {} //Constructor that initialize person name and age

    void display_person_details()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class employee : public person //Derived class employee that publically inharites feom peson 
{
protected:
    int employeeID;

public:
    employee(string n, int a, int id) : person(n, a), employeeID(id) {}
    void display_employee_details()
    {
        display_person_details();
        cout << "Employee ID: " << employeeID << endl;
    }
};
class manager : public employee //Derived class manager that publically inharites feom peson 
{
    string department;

public:
    manager(string n, int a, int id, string dept) : employee(n, a, id), department(dept) {}

    void display_manager_details()
    {
        display_employee_details();
        cout << "Department: " << department << endl;
    }
};

int main()
{
    // Create an array of 3 manager objects
    manager m[3] = {manager("Shivam", 18, 98, "CE"),
                    manager("Yash Gajera", 18, 22, "CS"),
                    manager("Ansh", 18, 100, "CE")};

    cout << "Details: " << endl; // Display details
    for (int i = 0; i < 3; i++)
    {
        m[i].display_manager_details();
        cout << endl;
    }

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
