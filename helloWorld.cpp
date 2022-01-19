#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

class A
{
	int x;
	int y;
	string name;
	static const int z = 12;
	public:
		A()
		{
			cout << "explicit Ctor\n";
			x = 99;
			y = 11;
		}

		A(int i) : x(i)
		{
			
		}

		A(string n)

		{	cout << "string Ctor\n";
			name = n;
			x = 10;
			y = 11;
		}

		virtual ~A()
		{
			cout << "deleting " << name << endl;
		}


		int getX()
		{
			return x;
		}

		void setX(int i)
		{
			x = i;
		}

		int getY()
		{
			return y;
		}

		A(const A& obj)
		{
			name = obj.name;
			x = obj.x;
			y = obj.y;

			cout << "copy constructor called\n";
		}

		A& operator=(const A& obj)
		{
			name = obj.name;
			x = obj.x;
			y = obj.y;

			cout << "assignment operator called\n";
		}

		//prefix
		A& operator++()
		{
			x++;

			return *this;
		}
		//postfix
		A operator++(int)
		{
			A temp = *this;
			++*this;
			return temp;

		}

		bool operator!=(const A& obj)
		{
			if (obj.name == this->name)
				return false;

			else
				return true;
		}

};

class B: public A
{	
	int y;
	public:

	B()
	{
		y = 22;
	}
	~B()
	{
		cout << "deleting B\n";
		
	}

	int getY()
	{
		return y;
	}
};

class C : public B
{
	int y;
	public:
	C()
	{
		y = 33;
	}

	int getY()
	{
		return y;
	}

};
/*A foo()
{
	A newObj(20,20);

	return newObj;
}
*/
A foo(A& ref)
{
	cout << ref.getY() << endl;
	A c("Nasim");

	return c;
}
bool isEqual(double x, double y)
{
	const float epsilon = 1e-5;

	if (abs(x-y) <= epsilon)
		return true;
	else
		return false;
}

void reverse(string& str)
{
	int start = 0;
	int end = str.length()-1;
	char temp;

	while(start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}



}

string binary(int num)
{
	string bin = "";

	while(num)
	{
		if(num & 0x1)
			bin += "1";
		else
			bin += "0";

		num >>= 1;
	}

	reverse(bin);

	return bin;
}

bool powerOf(int num, int pow)
{
	while(num%pow == 0)
	{
		num /= pow;
	}

	return num == 1;
}

int main()
{

B b;
C c;
A* aptr = &c;
B* bptr = &c;

cout << bptr->getY() <<endl;



}
