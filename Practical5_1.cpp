#include <iostream>
#include <vector>
using namespace std;

class calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }
    double add(double a, double b)
    {
        return (a + b);
    }
    double add(int a, double b)
    {
        return (a + b);
    }
};
int main()
{
    calculator calc;
    cout << "<-----------Using Non STL-------------->"<<endl;

    double result[3];
    result[0] = calc.add(4, 3);
    result[1] = calc.add(5.0, 3.2);
    result[2] = calc.add(4, 3.9);

    cout << "Result:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << result[i] << endl;
    }
    cout << "<------------Using STL-------------->"<<endl;

    vector<double> results;
    results.push_back(calc.add(4, 3));
    results.push_back(calc.add(5.0, 3.2));
    results.push_back(calc.add(4, 3.9));

    cout << "Results:" << endl;
    for (double r : results)
    {
        cout << r << endl;
    }

    cout << "\n\n24CE098_Shivam Prajapati\n\n"; 
    return 0;
}