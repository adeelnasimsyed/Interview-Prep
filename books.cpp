#include <iostream>
#include <stack>
using namespace std;


class Book
{
	int bookCode;
	float price;
	int inven;
	int enroll;
	int newB;
	int reqd;

public:
	Book(int bC, float p, int i, int e, int n, int r)
	{
		bookCode = bC;
		price = p;
		inven = i;
		enroll = e;
		newB = n;
		reqd = r;
	}

	int Need2Buy()
	{
		if(newB && reqd)
			return (int)(enroll*0.90) - inven;

		else if(!newB && reqd)
			return (int)(enroll*0.65) - inven;

		else if(newB && !reqd)
			return (int)(enroll*0.40) - inven;
		else
			return (int)(enroll*0.20) - inven;
	}

	float TotalCost()
	{
		return price * Need2Buy();
	}
};


int main()
{
	int bC, i, e, n, r;
	float p; 
	stack<Book> s;


		cout << "Please enter the book code: ";
		cin >> bC;
	/*	cout << "Single copy price: ";
		cin >> p;
		cout << "Number on hand: ";
		cin >> i;
		cout << "Prospective enrollment: ";
		cin >> e;
		cout << "1 for required/0 for optional: ";
		cin >> r;
		cout << "1 for new/0 for used: ";
		cin >> n;*/
		cout << "***********************************\n";
	
/*		Book temp(bC, p, i, e, n, r);
		s.push(temp);
*/
	return 0;
}