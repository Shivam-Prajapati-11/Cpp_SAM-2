#include <iostream>
#include <vector>
using namespace std;

class Students // Abstract Base Class
{
protected:
    float marks;

public:
    void setmarks(float m) //Setter method
    {
        marks = m;
    }

    virtual string Compute_Grade() = 0; // Pure virtual function
    virtual ~Students() {} // Virtual destructor
};
class undergraduate : public Students
{
public:
    string Compute_Grade() override
    {
        if (marks >= 85)
        {
            return "A";
        }
        else if (marks >= 65)
        {
            return "B";
        }
        else if (marks >= 45)
        {
            return "C";
        }
        else
        {
            return "F";
        }
    }
};
class postgraduate : public Students
{
public:
    string Compute_Grade() override
    {
        if (marks >= 90)
        {
            return "A";
        }
        else if (marks >= 75)
        {
            return "B";
        }
        else if (marks >= 55)
        {
            return "C";
        }
        else
        {
            return "F";
        }
    }
};

int main()
{
    vector<Students *> student; // Vector to store pointers to students(UG and PG)

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (size_t i = 0; i < n; ++i)
    {
        int type;
        float m;
        cout << "Enter type of students(1 for UG and 2 for PG): ";
        cin >> type;

        cout << "Enter Mark of student: ";
        cin >> m;

        Students *stu = nullptr; 

        if (type == 1)
        {
            stu = new undergraduate();
        }
        else if (type == 2)
        {
            stu = new postgraduate();
        }
        else
        {
            cout << "Invalid student!!!!!" << endl;
            continue;
        }
        stu->setmarks(m);
        student.push_back(stu);
    }

    // Display Grades
    cout << "Student Details: " << endl;
    for (size_t i = 0; i < student.size(); ++i)
    {
        cout << "Student " << i + 1 << " Grade: " << student[i]->Compute_Grade() << endl;
    }
    for (Students *s : student)
    {
        delete s;
    }

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}