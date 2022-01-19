#include <iostream>
#include <stack>
#include <string>

using namespace std;



bool balancedParentheses(char *C)
{
	int len = sizeof(C)/sizeof(char);
	int i = 0;
	stack<char> s;
	for(i = 0; i <= len; i++)
	{
		if (C[i] == '{' || C[i] == '[' || C[i] == '(') 
			s.push(C[i]);
		else if (C[i] == '}')
		{
			if (s.top() == '{')
				s.pop();
			else
				return false;
		}

		else if (C[i] == ']')
		{
			if (s.top() == '[')
				s.pop();
			else
				return false;
		}

		else
		{
			if(s.top() == '(')
				s.pop();
			else
				return false;
		}
	}

	return true;
}


int main()
{
	char C[20] = "{{[]}}";
	cout << balancedParentheses(C) << endl;

	return 0;
}