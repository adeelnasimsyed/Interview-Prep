#include <iostream>

using namespace std;

string reverseString(string s)
{
    char temp;
    int start = 0;
    int end = s.length() - 1;

    while(start < end)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }

    return s;


}

int main()
{
    string check = "Hello";
    check = reverseString(check);

    cout << check <<endl;

}