/*A university managing academic data for its students. The administration seeks to digitize the records
of student performance, including personal and academic details. The system must store each
student's roll number, name, and marks in three subjects. Additionally, it should provide
functionalities to calculate and display the average marks for performance analysis.
The institution's IT team proposed a solution where student records could be initialized in two ways:
either with default values for testing purposes or by accepting specific input details for each student.
Once initialized, the system would allow for viewing comprehensive student details, including their
roll number, name, marks, and calculated average. This functionality was designed to help faculty and
administrators track individual student performance efficiently.
To simulate real-world usage, the team decided to create multiple student records. They planned to
populate the system with a mix of students initialized using both default and specific values. The
system's ability to accurately calculate averages and display detailed student information was to be
tested with this data.*/

#include <iostream>
using namespace std;

class student //Create class of student
{
public:
    int roll_number;
    string name;
    double mark[3];

    student() //Default constructor called
    {
        roll_number = 0;
        name = "N/A";
        for (int i = 0; i < 3; i++)
        {
            mark[i] = 0;
        }
    }
    student(int r, string n, double m1, double m2, double m3) //Peramiterized constructor called
    {
        roll_number = r;
        name = n;
        mark[0] = m1;
        mark[1] = m2;
        mark[2] = m3;
    }
    void display_details() //Function that display details of student
    {
        cout << "Roll Number: " << roll_number << endl;
        cout << "Name:\t" << name << endl;
        cout << "Marks:\t" << mark[0] << "," << mark[1] << "," << mark[2] << endl;
    }
    void avg_marks() //Function that calculate average marks of student
    {
        double avg;
        avg = (mark[0] + mark[1] + mark[2] / 3.0);
        cout << "Average Marks: " << avg << endl;
    }
};

int main()
{
    student s[3]; //Create 3 object of class student
    s[0] = student(11, "Shivam", 85, 87, 93);
    s[1] = student(8, "Krunal", 80, 85, 89);
    s[2] = student(12, "Daksh", 89, 92, 96);

    for (int i = 0; i < 3; i++) //Using loop for displaying details and average
    {
        cout << endl
             << "Student " << i + 1 << " Details" << endl;
        s[i].display_details();
        s[i].avg_marks();
    }

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}