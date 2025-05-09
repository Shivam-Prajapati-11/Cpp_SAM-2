#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base Constructor Called" << endl;
    }

    virtual ~Base()
    {
        cout << "Base Destructor Called" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived Constructor Called" << endl;
    }

    ~Derived()
    {
        cout << "Derived Destructor Called" << endl;
    }
};

int main()
{
    Base* obj = new Derived();
    delete obj;

    
    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}