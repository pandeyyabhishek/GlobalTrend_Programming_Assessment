// 6. Write a function to find the factorial of a given number.The function should return the factorial of the number.

#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    cout << factorial(5) << endl; // Output: 120
    cout << factorial(0) << endl; // Output: 1
    return 0;
}
