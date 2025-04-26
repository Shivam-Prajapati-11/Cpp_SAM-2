/*A mid-sized retail store faced challenges in efficiently managing its inventory of items. The store's
management sought to build a system that could keep track of individual items, including details like
a unique item ID, item name, price, and the quantity available in stock. The need for a streamlined
process arose due to frequent stock discrepancies, which led to issues with customer satisfaction and
operational efficiency.
To address this, the store hired a team of developers to create a digital inventory management system.
The envisioned solution would allow for the initialization of item details, either with default values or
specific attributes like ID, name, price, and starting quantity. This system needed to handle operations
like increasing stock levels when new shipments arrived and decreasing stock when items were sold,
ensuring sufficient inventory was available for each transaction. Additionally, the system would
provide clear, detailed summaries of each item's status, aiding in decision-making and reporting.
The developers faced real-world scenarios where they had to manage multiple inventory items
simultaneously. They planned to design an array of inventory items and simulate common tasks such
as adding stock, processing sales transactions, and displaying the current inventory details. Handling
edge cases, such as attempting to sell more items than available in stock, became a critical part of the
implementation to ensure reliability.*/

#include <iostream>

using namespace std;

class Inventory //Create class of inventory
{
    int itemId;
    string ItemName;
    int price;
    int quantity;

public:
    Inventory() //Default constructor called
    {
        itemId = 0;
        ItemName = "N/A";
        price = 0;
        quantity = 0;
    }
    Inventory(int id, string name, int p, int q) //Parametrized constructor called
    {
        itemId = id;
        ItemName = name;
        price = p;
        quantity = q;
    }
    void addStock(int qty) //Funtion that add item
    {
        // Quntity added
        quantity += qty;
        cout << qty << " Quantity will be added to " << ItemName << endl;
    }
    void sellItem(int qty) //Function that sell item
    {
        if (qty > quantity) //Check whether item available or not 
        {
            cout << "We have " << ItemName << "'s limited stock!" << endl
                 << "Available stock: " << quantity;
        }
        else
        {
            quantity -= qty;
            cout << qty << " Quantity will be sold" << ItemName << endl;
        }
    }
    void display() //Function that display item's details
    {
        cout << endl
             << "ItemId: " << itemId << endl;
        cout << "ItemName: " << ItemName << endl;
        cout << "Item Price: " << price << endl;
        cout << "Item Quantity: " << quantity << endl;
    }
};

int main()
{
    //Cerating an object of inventory
    Inventory I1(1211, "Watermalon", 15, 20);
    Inventory I2(1212, "Banana", 8, 30);
    Inventory I3(1213, "Apple", 20, 40);

    I1.display();
    I2.display();
    I3.display();

    I1.addStock(6);
    I3.sellItem(5);

    I1.display();
    I2.display();
    I3.display();

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}