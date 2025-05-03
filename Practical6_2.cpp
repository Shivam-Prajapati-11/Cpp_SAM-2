#include<iostream>
using namespace std;

class point // Class to represent a 2D point
{
    int x,y;
public:
    // Constructor with default parameters
    point(int x=0,int y=0)
    {
        this->x = x;
        this->y = y;
    }
    point* move(int &dx,int &dy)
    {
        x+= dx;
        y+=dy;
        return this; // Return current object for chaining
    }
    // Display the current coordinates of the point
    void display() const
    {
        cout<<"Point: "<<endl<<"("<<x<<" , "<<y<<")"<<endl;
    }
};

int main()
{
    int x,y;
    cout<<"Enter the initial x and y coordinates: "<<endl;
    cin>>x>>y;

    // Dynamically allocate a point object with given coordinates
    point* p = new point(x,y);

    cout<<"Initial position: "<<endl;
    p->display();

    // Get first move values
    int dx1,dy1,dx2,dy2;
    cout<<"Enter dx1 and dy1: "<<endl;
    cin>>dx1>>dy1;

    cout<<"Enter dx2 and dy2: "<<endl;
    cin>>dx2>>dy2;

    // Move the point twice using method chaining
    p->move(dx1,dy1)->move(dx2,dy2);

    // Show the updated position after both moves
    cout<<"Updated position: "<<endl;
    p->display();

    // Deallocate the dynamically allocated point
    delete p;

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
