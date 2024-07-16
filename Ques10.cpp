/*
10.	Write a function to check if a given string contains only alphabetic characters.The function should return true if the string contains only alphabetic characters, and false otherwise.
*/

#include <iostream>
using namespace std;

bool isAlphabetic(const string &s)
{
    for (char c : s)
    {
        if (!isalpha(c))
            return false;
    }
    return true;
}

int main()
{
    cout << isAlphabetic("Hello") << endl;    // Output: 1 (true)
    cout << isAlphabetic("Hello123") << endl; // Output: 0 (false)
    return 0;
}
