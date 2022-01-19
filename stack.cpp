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
    
    ~Node()
    {   
        
        cout << "Deleting " << this->data << endl;
        
    }
};


class Stack
{
    private:
        Node *head;

    public:

        Stack();
        ~Stack();
        void Push(int i);
        void Print();
        int Pop();
        bool isEmpty();
};

Stack::Stack()
{
    this->head = NULL;
}

Stack::~Stack()
{

    Node *ptr = this->head;
    Node *temp;
    while(ptr != NULL)
    {   
        temp = ptr->next;
        delete ptr;
        ptr  = temp;
    }
}

void Stack::Push(int i)
{
    Node* node = new Node(i);
    if (this->head == NULL)
    {
        this->head = node;
        return;
    }

    
    node->next = this->head;
    this->head = node;

}

void Stack::Print()
{
    Node *ptr = this->head;

    while(ptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

bool Stack::isEmpty()
{
    if (this->head == NULL)
        return true;
    else
        return false;
}


int Stack::Pop()
{
    int retval = -1;

    if (this->head != NULL)
    {   
        Node *ptr = this->head;
        retval = ptr->data;
        this->head = ptr->next;
        delete ptr;

    }

    return retval;
}

int main()
{

    Stack *s = new Stack;
    s->Push(1);
    s->Push(2);
    s->Push(3);
    s->Print();
    cout << s->Pop() << endl;
    delete s;
    return 0;
}

