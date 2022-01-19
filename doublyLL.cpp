#include <iostream>

using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;
  public:
 

    Node(int i = 0)
    {
        this->data = i;
        this->next = NULL;
        this->prev = NULL;
    }
    
    ~Node()
    {   
        
        cout << "Deleting " << this->data << endl;
        
    }

    friend class DoublyLinkedList;
};


class DoublyLinkedList
{

  public:
    Node* head;

    DoublyLinkedList(Node* headNode)
    {
        this->head = headNode;
    }
    
    ~DoublyLinkedList()
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

    void PrintForward()
    {
        Node *node = this->head;

        while(node)
        {
            cout << node->data << endl;
            node = node->next;
        }
        
    }

    void PrintRevUtil(Node *node)
    {
        if (node == NULL)
            return;
        PrintRevUtil(node->next);
        cout << node->data << endl;
    }

    void PrintReverse()
    {
        Node *node = this->head;
        PrintRevUtil(node);

    }

    void Insert(int i)
    {
        Node *node = new Node(i);
        Node *ptr = this->head;

        while(ptr->next)
        {
            ptr = ptr->next;
        }

        ptr->next = node;
        node->prev = ptr;
    }

    void InsertAtIndex(int i, int n)
    {
        Node *node = new Node(i);
        int idx = 0;
        if (n == 0)
        {
            this->head->prev = node;
            node->next = this->head;
            this->head = node;
        }

        else
        {
            Node *ptr = this->head;
            while(ptr->next != NULL && idx < n-1)
            {
                ptr = ptr->next;
                idx++;
            }

            node->next = ptr->next;
            ptr->next = node;
            if (node->next != NULL)
                node->next->prev = node;

        }
    }

};


int main()
{
    Node *head = new Node(5);
    DoublyLinkedList* dll = new DoublyLinkedList(head);

    dll->Insert(2);
    dll->Insert(4);
    dll->Insert(9);
    dll->InsertAtIndex(1,0);
    dll->InsertAtIndex(7,2);
    dll->PrintForward();
    return 0;
}