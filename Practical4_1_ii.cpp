#include <iostream>
#include <vector>
using namespace std;

class shape // Create base class named shape
{
protected:
    double radius;

public:
    shape(double r) // Constructor that initialize the radius
    {
        radius = r;
    }
    double get_radius()
    {
        return radius;
    }
};
class circle : public shape // Derived class circle that publically inharites from shape 
{
    double area;

public:
    circle(double r) : shape(r), area(0)
    {
        area = 0;
    }
    void calculate_area() // Function that calculate the area of the circle
    {
        area = 3.14 * radius * radius;
    }
    void display() // Function that display the area
    {
        cout << "The area of radius " << radius << " is " << area << endl;
    }
    double getarea() //Funcion that get area 
    {
        return area;
    }
};

int main()
{
    double num;

    cout << "Enter the number of radius: ";
    cin >> num; //Ask user for number of radius 

    vector<circle> circles; // Vector to store multiple circle objects

    for (int i = 0; i < num; i++) // Input and create circle objects dynamically
    {
        double radius;
        cout << "Enter the radius of circle " << i + 1 << ": ";
        cin >> radius;

        // Create a circle object, calculate its area, and add to the vector
        circle c(radius);
        c.calculate_area();
        circles.push_back(c);
    }

    // Display the details of each circle
    for (int i = 0; i < circles.size(); i++)
    {
        circles[i].display();
    }

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
