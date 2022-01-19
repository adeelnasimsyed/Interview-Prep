#include <iostream>


using namespace std;

class A
{
	private:
		int a;

	protected:
		int b;

		int getB()
		{
			return b;
		}

	public:
		int c;
		A()
		{
			a = 10;
			b = 12;
			c = 14;
			cout << "Constructor called : A\n";
		}

		A(const A& obj)
		{
			cout << "Copy constructor called\n";
			a = obj.a;
		}

		virtual ~A()
		{
			cout << "Destructor called : A\n";
		}

		int getA()
		{
			return a;
		}


		virtual int getC()
		{
			return c+1;
		}

};


class B : public A
{
	public:
	B()
	{
		cout << "Constructor called : B\n";
	}

	~B()
	{
			cout << "Destructor called : B\n";
	}


	int get()
	{
		return getB();
	}

	int getC()
	{
		return c;
	}



};

void myFunc(A obj)
{
	cout << obj.getA() << endl;
}

void print()
{
	cout << "print1\n";
}

int print(int a)
{
	cout << "print2\n";
	return a;
}

int main()
{
/*	A a;

	B b;
	cout << b.get() << endl;*/
/*
	A a;
	myFunc(a);*/

	A a;
	A b;

	print();
	print(2);
}


/*

public: Base class public and protected methods/data are copied over to derived, as 
		public and protected. Outside world has access to base public methods/data  

protected: Base class public/protected methods and objects are copied over
			as protected. Outside world does not have access to base public methods/data

private: Base class public/protected methods/data copied over as private. Outside world
		 or derived of class do not have access to base class methods/data

*/