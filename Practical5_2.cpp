#include <iostream>
#include <vector>
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {} // Constructor with default arguments

    Complex operator+(Complex c) // Overload the + operator to add two complex numbers
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    Complex operator-(Complex c) // Overload the - operator to subtract two complex numbers
    {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
    friend istream &operator>>(istream &in, Complex &c) // Friend function to overload >> operator for input
    {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Complex &c) // Friend function to overload << operator for output
    {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};
int main()
{
    Complex c1, c2;
    //Take input from the user
    cout << "Enter first complex number:" << endl;
    cin >> c1;
    cout << "Enter second complex number:" << endl;
    cin >> c2;

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;

    cout << "Sum of complex: " << sum << endl;
    cout << "Difference of complex: " << difference << endl;

    // Working with collections
    vector<Complex> c = {c1, c2};
    c.push_back(sum);
    c.push_back(difference);

    cout << "Complex numbers:" << endl;
    for (const auto &comp : c)
    {
        cout << comp << endl;
    }

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}