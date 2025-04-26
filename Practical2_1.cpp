/*A local construction company frequently deals with rectangular plots and structures of varying
dimensions. To streamline their planning and estimation processes, the company requires a simple
system to manage and analyze rectangular shapes efficiently.
The system must be able to handle multiple rectangles, each with distinct dimensions. For each
rectangle, the length and width need to be defined and stored securely. Additionally, the company
needs the ability to calculate two key metrics for any given rectangle:
The area, to estimate usable space or material coverage. The perimeter, to estimate boundary lengths
or material requirements for edges. To make this system functional, there should be a way to define
or update the dimensions of any rectangle as required. The system should be capable of creating and
managing multiple rectangle records, performing calculations for each, and displaying the results
clearly for analysis and planning purposes.*/

#include <iostream>
using namespace std;

class rectangle //create ractangle class
{
private:
    double length;
    double width;

public:
    rectangle(double l, double w) //Parametrized constructor called
    {
        length = l;
        width = w;
    }
    double area() //calculate area
    {
        return (length * width);
    }
    double perimeter() //calculate perimeter
    {
        return 2 * (length + width);
    }
};

int main()
{
    rectangle r1(4, 3); //create an object of rectangle
    cout << "Area of r1: " << r1.area() << ",Parimeter of r1: " << r1.perimeter() << endl;

    rectangle r2(7, 7); //create an object of rectangle
    cout << "Area of r1: " << r2.area() << ",Parimeter of r1: " << r2.perimeter() << endl;

    rectangle r3(5, 6); //create an object of rectangle
    cout << "Area of r1: " << r3.area() << ",Parimeter of r1: " << r3.perimeter() << endl;

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}