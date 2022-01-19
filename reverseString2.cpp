#include <iostream>
#include <stack>
#include <string>

using namespace std;


void reverseString(char *C)
{
	int len = sizeof(C)/sizeof(char);
	int i = 0;
	stack<char> s;
	for(i = 0; i <= len; i++)
	{
		s.push(C[i]);
	}

	for(i = 0; i <= len; i++)
	{
		C[i] = s.top();
		s.pop();
	}

}


int main()
{
	char C[20] = "Hello";
	reverseString(C);

	cout << C << endl;
	return 0;
}