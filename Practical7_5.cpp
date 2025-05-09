#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


ostream& currency(ostream& os) {
    return os << "₹";
}

void displayReport() {

    string students[] = {"Shivam", "Nirav", "KIshan", "Yash"};
    double marks[] = {96, 92.0, 86.4, 61.2};
    double tuitionFees[] = {520000.75, 428000.50, 535000.25, 479000.00};

    cout << "\n--- Student Marks and Tuition Fees ---\n";


    cout << left << setw(20) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;


    cout << setfill('-') << setw(20) << ""
         << setw(10) << ""
         << setw(15) << "" << setfill(' ') << endl;


    for (int i = 0; i < 4; ++i) {
        cout << left << setw(20) << students[i]
             << setw(10) << fixed << setprecision(1) << marks[i]
             << setw(2) << "$" << fixed << setprecision(2) << tuitionFees[i] << endl;
    }
}

int main() {
    displayReport();

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}