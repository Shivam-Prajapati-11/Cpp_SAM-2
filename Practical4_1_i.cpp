#include<iostream>
using namespace std;

class shape //Create base class named shape
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
    circle(double r):shape(r),area(0)
    {
        area = 0;
    }
    void calculate_area() // Function that calculate the area of the circle
    {
        area = 3.14 * radius * radius;
    }
    void display() // Function that display the area
    {
        cout<<"The area of radius "<<radius<<" is "<<area<<endl;
    }
};

int main()
{
    double radius;

    cout<<"Enter the circle of radius: ";
    cin>>radius; // Take radius input from the user

    circle c(radius);

    // Calculate and display the area
    c.calculate_area();
    c.display();

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
