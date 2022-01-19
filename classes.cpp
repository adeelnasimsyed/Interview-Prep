#include <iostream>
#include <cstdio>

using namespace std;

#if 0
class A 
{
	private:
		int i;

	public:
		A(int num = 0)
		{
			this->i = num;
		}

		bool operator == (const A& d)
		{
			if (this->i == d.i)
				return true;
			else
				return false;
		}


};


int main()
{

	A a;
	A b(0);

	if (a == b)
		cout << "same\n";
	else
		cout << "not same \n";
	return 0;
}
#endif
void fun(int *p1) 
{ 
printf("%d\n", *p1);
  int q = 10; 
  p1 = &q; 

  printf("%d\n", *p1);
}     
   
int main() 
{ 
  int r = 20; 
  int *p = &r; 
  fun(p); 
  printf("%d", *p); 
  return 0; 
}