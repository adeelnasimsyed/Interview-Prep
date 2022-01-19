#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

//My compiler is old, this builds on online CPP compiler

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second != b.second) 
	{ 
		return a.second > b.second; 
	} 

	return a.first < b.first; 
}

string stripSymbols(string word)
{
	char chars[] = ",!_+=-@";

	for(unsigned int i = 0; i < strlen(chars); i++)
	{
		word.erase(remove(word.begin(), word.end(), chars[i]), word.end());
	}

	return word;
}

void frequentWords(string input, int numWords, string output[])
{
	stringstream ss(input);
	string buf;
	map<string, int> map;
	vector<pair<string, int>>v;
	

	while(ss >> buf)
	{
		transform(buf.begin(), buf.end(), buf.begin(), ::tolower);
		buf = stripSymbols(buf);
		map[buf]++;
	}



	for (auto itr = map.begin(); itr != map.end(); itr++)
	{
		cout << itr->first << ": " << itr->second << endl;
		v.push_back(*itr);
	}

	sort(v.begin(), v.end(), cmp);

	int i = -1;

	for(auto itr = v.begin(); itr != v.end(); itr++)
	{	
	    i++;
	    output[i] = itr->first;
	    
	    if(i >= numWords-1)
	        break;
	}
	
	for(i = 0; i < numWords; i++)
	cout << output[i] << endl;
} 


int main()
{
	string a = "apple apple apple azdy azdy azdy Gabba gabba hey, gabba gabba hey!";
	int freqWords = 2;
	string output[freqWords];

	frequentWords(a,freqWords, output);

	return 0;
}
