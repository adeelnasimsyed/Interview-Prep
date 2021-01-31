
/*using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>

template <class T>
T median (vector<T> v)
{
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();

	if(size == 0)
	{
		throw domain_error("empty vector");
	}

	sort(v.begin(), v.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (v[mid] + v[mid-1])/2 : v[mid];
}

int main()
{
	/*vector<int> vec;
	int num = 0;
	srand((unsigned) time(0));

	for(int i = 0; i < 5; i++)
	{
		vec[i] = rand()%10 + 1;
	}

	num = median(v);*/
/*	int num = 0;
	cout << num <<endl;

	return 0;
}
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
T median (vector<T> v) {
  T result;
  result = v[0];
  return (result);
}


/*template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}*/

int main () 
{
	vector<int> vec;
	int num = 0;
	srand((unsigned) time(0));

	for(int i = 0; i < 5; i++)
	{
		vec[i] = rand()%10 + 1;
	}

	num = median (vec);

	cout << num <<endl;

  return 0;
}