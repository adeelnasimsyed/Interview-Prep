#include <iostream>

using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    
    Node(int i = 0)
    {
        this->data = i;
        this->next = NULL;
    }
    
/*    ~Node()
    {   
        
        cout << "Deleting " << this->data << endl;
        
    }*/
};

class Queue
{
    private:
        Node *front;
        Node *rear;

    public:
		Queue();
        ~Queue();
        void Enqueue(int i);
        bool isEmpty();
        void Print();
        int Dequeue();
        int Front();
        int Back();
};


Queue::Queue()
{
	this->front = NULL;
	this->rear = NULL;
}

Queue::~Queue()
{

    Node *ptr = this->front;
    Node *temp;
    while(ptr != NULL)
    {   
        temp = ptr->next;
        delete ptr;
        ptr  = temp;
    }
}

void Queue::Print()
{
    Node *ptr = this->front;

    while(ptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

bool Queue::isEmpty()
{
	if(this->front == NULL)
		return true;
	else
		return false;
}

int Queue::Front()
{
	return this->front->data;
}

int Queue::Back()
{
	return this->rear->data;
}

void Queue::Enqueue(int i)
{
	Node *node = new Node(i);

	if (this->front == NULL && this->rear == NULL)
	{
		this->front = node;
		this->rear = node;
	}

	else
	{
		Node *ptr = this->rear;
		ptr->next = node;
		ptr = ptr->next;
		this->rear = ptr;
	}

}

int Queue::Dequeue()
{

	int retval = 0;
	if (this->front != NULL)
	{
		Node *ptr = this->front;
		Node *temp;

		retval = ptr->data;
		temp = ptr;
		ptr = ptr->next;

		this->front = ptr;
		delete temp;

	}

	else
	{
		cout << "Empty Queue\n";
		retval = -1;
	}
	

	return retval;

}


int main()
{

	Queue *q = new Queue;

	q->Enqueue(1);
	q->Enqueue(2);
	q->Enqueue(3);
	q->Enqueue(4);
	q->Enqueue(5);
	q->Enqueue(6);
	cout << "Front of queue is: " << q->Front() << endl;
	cout << "Rear of queue is: " << q->Back() << endl;
	q->Print();

	delete q;


}