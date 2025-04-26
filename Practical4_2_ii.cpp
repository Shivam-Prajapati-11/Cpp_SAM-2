#include <iostream>
#include <string>
#include <vector>
using namespace std;

class person
{
protected:
    string name;
    int age;

public:
    person(string n, int a) : name(n), age(a) {}

    void display_person_details() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class employee : public person
{
protected:
    int employeeID;

public:
    employee(string n, int a, int id) : person(n, a), employeeID(id) {}
    void display_employee_details() const
    {
        display_person_details();
        cout << "Employee ID: " << employeeID << endl;
    }
};
class manager : public employee
{
    string department;

public:
    manager(string n, int a, int id, string dept) : employee(n, a, id), department(dept) {}

    void display_manager_details() const
    {
        display_employee_details();
        cout << "Department: " << department << endl;
    }
};

int main()
{
    vector<manager> m;
    m.push_back(manager("Shivam", 18, 98, "CE"));
    m.push_back(manager("Yash Gajera", 18, 22, "CS"));
    m.push_back(manager("Ansh", 18, 100, "CE"));

    for (auto &i : m)
    {
        i.display_manager_details();
        cout << endl;
    }

    // map<int,manager> m;

    // m[98] = manager("Shivam",18,98,"CE");
    // m[22] = manager("Yash Gajera",18,22,"CS");
    // m[100] = manager("Ansh",18,100,"CE");

    // for(auto &i : m)
    // {
    //     cout<<"ID: "<<i.first<<endl;
    //     // i.second.display_manager_details();
    //     i.second.display_manager_details();
    // }

    /*manager m[3] = {manager("Shivam",18,98,"CE"),
                    manager("Yash Gajera",18,22,"CS"),
                    manager("Ansh",18,100,"CE")
                   };
    cout<<"Details: "<<endl;
    for(int i = 0; i<3; i++)
    {
        m[i].display_manager_details();
        cout<<endl;
    }*/

    return 0;
}
