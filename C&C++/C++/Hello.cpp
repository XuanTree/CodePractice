#include <iostream>

using namespace std;

namespace First{
    int x = 1;
}
int main()
{
    cout << "Hello C++ !" << endl;

    int price = 100;

    cout << "The price is " << price << endl;

    cout << First:: x << endl;
    return 0;
}