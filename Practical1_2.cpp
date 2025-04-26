/*A small retail store is facing challenges in managing its inventory effectively. The store sells a
variety of products, each identified by a unique product ID, a name, the available quantity in
stock, and the price per unit. To streamline their operations, the store needs a basic system to
manage this inventory efficiently.
The system must provide the ability to add new products to the inventory, ensuring that each
product has its ID, name, quantity, and price properly recorded. Additionally, the system should
allow the store staff to update the quantity of any existing product, such as when new stock
arrives or when items are sold.
Another essential feature of the system is the calculation of the total value of all products in
the inventory, which is determined by multiplying the quantity of each product by its price and
summing these values for all products.

The store management is exploring two approaches for this system: a procedural approach and
an object-oriented approach. The goal is to evaluate these approaches by comparing their ease
of implementation, code reusability, and overall complexity.
The system's design and implementation should consider these requirements and provide an
effective solution (either procedural approach or an object-oriented approach) to the store's
inventory management problems. */

#include <iostream>
#include <string>

using namespace std;

const int maxproduct = 100;

struct Product //Create basic structure of name product
{
    int id;
    string name;
    int quantity;
    float price;
};

Product inventory[maxproduct]; //array that store the inventory
int productcount = 0; //productcount initialize with 0 

void addproduct(int id, string name, int quantity, float price) // Function that add a new product to the inventory
{
    if (productcount >= maxproduct)
    {
        cout << "Inventory is full!!!" << endl;
    }
    inventory[productcount] = {id, name, quantity, price}; // Add product to inventory
    productcount++;
    cout << "Product: " << name << " Add" << endl;
}

void updatequantity(int id, int newquantity) // Function that update the quantity of product
{
    for (int i = 0; i < productcount; i++)
    {
        if (inventory[i].id == id)
        {
            inventory[i].quantity = newquantity;
            cout << "Quantity updated!!!" << endl
                 << "ID: " << id << endl;
        }
    }
}
int calculate_total_value() // Function that calculate the total value of all products in inventory
{
    double total = 0;
    for (int i = 0; i < productcount; i++)
    {
        total += inventory[i].quantity * inventory[i].price;
    }
    return total;
}
void display_inventory() //Function that display products
{
    cout << endl
         << "Details of Inventory: " << endl;
    cout << "ID\tNAME\t\tQUANTITY\tPRICE" << endl;
    for (int i = 0; i < productcount; i++)
    {
        cout << inventory[i].id << "\t"
             << inventory[i].name << "\t\t"
             << inventory[i].quantity << "\t\t"
             << inventory[i].price << "\t" << endl;
    }
}
int main()
{
    //add product 
    addproduct(1, "IPhone", 7, 149000.00);
    addproduct(2, "Samsung", 10, 223000.00);
    addproduct(3, "Vivo", 5, 100000.00);

    updatequantity(3, 2); //it is update quantity

    display_inventory();

    cout << "Total inventory value: " << calculate_total_value() << endl; // show total inventory value

    cout << "\n\n24CE098_Shivam Prajapati\n\n";

    return 0;
}