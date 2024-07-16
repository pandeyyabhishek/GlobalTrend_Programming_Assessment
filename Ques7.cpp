// 7. Write a function to compute the sum of the digits of a given number.The function should return the sum of the digits of the number.

#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    cout << sumOfDigits(123) << endl;  // Output: 6
    cout << sumOfDigits(4567) << endl; // Output: 22
    return 0;
}
