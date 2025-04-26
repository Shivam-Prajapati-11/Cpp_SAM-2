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

// #include <iostream>
// #include <queue>
// using namespace std;

// class fuel
// {
// protected:
//     string fuel_type;

// public:
//     fuel(string fu) : fuel_type(fu) {}

//     void display_fuel() const
//     {
//         cout << "Fule Type: " << fuel_type << endl;
//     }
// };
// class brand
// {
// protected:
//     string brand_name;

// public:
//     brand(string Br) : brand_name(Br) {}

//     void display_brand() const
//     {
//         cout << "Brand Name: " << brand_name << endl;
//     }
// };

// class car : public fuel,public brand
// {
//     private:
//         string model;
//     public:
//         car(string fuel,string brand,string mdl) : fuel(fuel),brand(brand),model(mdl) {}

//     void display_car() const
//     {
//         display_brand();
//         display_car();
//         cout<<"Model: "<<model<<endl;
//     }
// };

// int main()
// {
//     queue<car> c;

//     c.push(car("Petrol","Verna","A15"));
//     c.push(car("CNG","EON","Meghna+"));
//     c.push(car("Diesel","Creta","A1"));

//     cout<<"CAR queue"<<endl;
//     while (!c.empty())
//     {
//         car C = c.front();
//         C.display_car();
//         c.pop();
//     }
//     // const int car_count = 3;
//     // car cararrv[car_count] = ;

//     return 0;
// }
#include <iostream>
#include <queue>
#include <memory> // For smart pointers

using namespace std;

class fuel
{
protected:
    string fuel_type;

public:
    fuel(const string fu) : fuel_type(fu) {}

    void display_fuel() const
    {
        cout << "Fuel Type: " << fuel_type << endl;
    }
};

class brand
{
protected:
    string brand_name;

public:
    brand(const string Br) : brand_name(Br) {}

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
    car(const string fueltype, const string brandname, const string mdl) : fuel(fueltype), brand(brandname), model(mdl) {}

    void display_car() const
    {
        display_brand();
        display_fuel(); // Fixed: Call display_fuel() instead of display_car()
        cout << "Model: " << model << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    queue<shared_ptr<car>> c; // Using smart pointers to handle cars safely

    c.push(make_shared<car>("Petrol", "Hyundai", "Verna A15"));
    c.push(make_shared<car>("CNG", "Hyundai", "EON Meghna+"));
    c.push(make_shared<car>("Diesel", "Hyundai", "Creta A1"));

    cout << "CAR Queue:" << endl;
    while (!c.empty())
    {
        c.front()->display_car(); // Display car details
        c.pop();
    }

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
