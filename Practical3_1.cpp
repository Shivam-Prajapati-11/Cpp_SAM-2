/*A growing organization sought to enhance its payroll process to improve accuracy and efficiency in
calculating employee salaries. The goal was to manage details such as the employee's name, basic
salary, and bonus amount. While most employees would receive a default bonus, there was a need
for flexibility to provide customized bonuses for exceptional performers or those in specialized roles.
To ensure real-time computation of each employee's total salary, the system would dynamically
calculate the total salary by adding the basic salary and the bonus. An inline function was chosen for
this task, allowing the system to compute the total salary instantly during processing. The system was
designed to initialize employee records using a constructor, where the bonus could either be set to a
default value or adjusted according to specific employee criteria.
As the organization expanded, managing employee records efficiently became a key consideration.
The solution involved storing employee details dynamically, ensuring the system could handle a
growing number of records while maintaining scalability and flexibility. Each employee record would
include their personal details, basic salary, and bonus information, with the system displaying a
breakdown of each employee’s details along with their total salary.*/

#include <iostream>
#include <vector>

using namespace std;

class employee //Create class of employee
{
    string emp_name;
    int emp_salary;
    double bonus;

public:
    employee(string name, int salary, double b = 500) // Parameter Counstructor
    {
        emp_name = name;
        emp_salary = salary;
        bonus = b;
    }

    inline float total_salary() const //function that return total salary using inline keyword and keep constant
    {
        return emp_salary + bonus;
    }
    void display() const //Function that display employee details
    {
        cout << "<--------------------------->" << endl;
        cout << "Name: " << emp_name << endl;
        cout << "Basic Salary: " << emp_salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << total_salary() << endl;
    }
};

int main()
{
    vector<employee> e; //Vector that dinamically store employee records

    // e.push_back(employee("Shivam",50000));
    e.emplace_back(employee("Shivam", 50000));
    e.emplace_back(employee("Het", 20000, 1000));
    e.emplace_back(employee("Yash", 70000));

    for (auto &i : e) //Display details using ranged based loop
    {
        i.display();
    }

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
