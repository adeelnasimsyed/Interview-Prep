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

class LinkedList
{
  public:
    Node* head;
    LinkedList(Node* headNode)
    {
        this->head = headNode;
    }
    
    ~LinkedList()
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
    
    void Print()
    {
        Node*ptr = this->head;
        
        while(ptr)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
        
    }
    
    void Insert(int i)
    {
        Node*ptr = this->head;
        
        while(ptr->next)
        {
            ptr = ptr->next;
        }
        
        ptr->next = new Node(i);
    }
    
    void InsertAtIndex(int i, int n)
    {
        Node *node = new Node(i);
        int idx = 0;
        if (n == 0)
        {
            node->next = this->head;
            this->head = node;
        }
        
        else
        {
            Node* ptr = this->head;
            
            while(ptr->next != NULL && idx < n-1) 
            {
                ptr = ptr->next;
                idx++;
             
            }
            
            node->next = ptr->next;
            ptr->next = node;
        }
    }
  
    void DeleteAtIndex(int n)
    {
        
        Node* ptr = this->head;
      
        if (n == 0)
        {
            this->head = ptr->next;
            delete ptr;
        }
        
        else
        {
            Node * temp;
            int idx = 0;
            while(ptr->next != NULL && idx < n-1)
            {
                ptr = ptr->next;
                idx++;
                 
            }
            
            temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
        }
       
    }
  
  void Reverse()
  {
      Node* prev, *curr, *next;
      
      prev = NULL;
      curr = this->head;
      next = NULL;
      
      while(curr != NULL)
      {
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
      } 
    
      this->head = prev;
  }

void RevereUtil(Node *ptr)
{
  if(ptr->next == NULL)
  {
    this->head = ptr;
    return;
  }

  RevereUtil(ptr->next);
  Node *newPtr = ptr->next;
  newPtr->next = ptr;
  ptr->next = NULL;
}

void ReverseRecursion()
{
  if(this->head == NULL)
    return;

  RevereUtil(this->head);
}
    
};


int main()
{
  Node * head = new Node(5);
  LinkedList* l = new LinkedList(head);
  l->Insert(3);
  l->Insert(4);
  l->Insert(7);
  l->InsertAtIndex(9, 10);
  l->InsertAtIndex(10, 9);
  l->ReverseRecursion();
  l->Print();
  delete l;
  return 0;
}