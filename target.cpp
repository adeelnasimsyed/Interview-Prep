#include <iostream>
#include <map>
#include <utility>

using namespace std;
// For the given input above function would return pair [2,7]

bool foo( int target, int *input, int *output ) 
{	
	map<int,int> m;
	int i = 0;
	int len =  (sizeof(input)/sizeof(int));

	for(i = 0; i < len; i++)
		m[input[i]] = i;

	for(i = 0 ; i < len; i++)
	{
		auto itr = m.find(target - input[i]) ;
		if (itr != m.end())
		{	
			output[0] = itr->first;
			output[1] = input[i];
			return true;
		}
	}
	return false;	
}

int main()
{	
	int target = 9;
	int input [] = { 2, 5, 7, 11, 15 };  // assume that input is always sorted by ascending
	int output[2]; 

	cout << foo(target, input, output) << endl;
	return 0;
}