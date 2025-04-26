// /*A vehicle manufacturing company sought to create a robust system to organize and manage the
// details of various cars produced under its brand. To accomplish this, a hierarchical structure was
// conceptualized, reflecting the essential components of a vehicle. At the foundation, a class was
// designed to represent the type of fuel a vehicle uses. Another class was created to capture the brand
// name of the vehicle. These two foundational elements were then combined into a derived class
// specifically representing cars, integrating both fuel type and brand information.
// Constructors were used at each level to ensure proper initialization of attributes, allowing seamless
// integration of all details. Additionally, the ability to display complete information about a car, including
// its fuel type and brand, was incorporated into the system. To simulate a real-world scenario such as a
// service queue, multiple cars were organized and processed sequentially using a structured approach.
// This not only streamlined the handling of cars but also provided an opportunity to compare different
// methods of managing the collection and processing of vehicle data.*/

#include <iostream>
#include <queue>
using namespace std;

class fuel
{
protected:
    string fuel_type;

public:
    fuel(const string &fu) : fuel_type(fu) {}

    void display_fuel() const
    {
        cout << "Fule Type: " << fuel_type << endl;
    }
};
class brand
{
protected:
    string brand_name;

public:
    brand(const string &Br) : brand_name(Br) {}

    void display_brand() const
    {
        cout << "Brand Name: " << brand_name << endl;
    }
};

class car : public fuel, public brand
{
private:
    string model;

public:
    car(const string &fu, const string &br, const string &mdl) : fuel(fu), brand(br), model(mdl) {}

    void display_car() const
    {
        display_brand();
        display_fuel();
        cout << "Model: " << model << endl;
        cout << "--------------------------" << endl;
    }
};

int main()
{
    queue<car> c;

    c.push(car("Petrol", "Verna", "A15"));
    c.push(car("CNG", "EON", "Meghna+"));
    c.push(car("Gasoline", "Toyota", "Corolla"));

    cout << "CAR queue" << endl;
    while (!c.empty())
    {
        car C = c.front();
        C.display_car();
        c.pop();
    }
    const int car_count = 3;
    car car_arr[car_count] = {car("Civic", "Honda", "Hybrid"),
                              car("M5", "BMW", "Gasoline"),
                              car("Leaf", "Nissan", "Electric")};

    for (int i = 0; i < car_count; i++)
    {
        car_arr[i].display_car();
    }

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
