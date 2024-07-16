// 8. Write a function to find the greatest common divisor(GCD)
// of two numbers.The function should return the GCD of a and b.

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    cout << gcd(48, 18) << endl; // Output: 6
    cout << gcd(56, 98) << endl; // Output: 14
    return 0;
}
