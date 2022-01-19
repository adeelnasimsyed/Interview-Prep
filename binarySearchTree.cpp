#include <iostream>
#include <stack>

using namespace std;

class Node
{

  public:

    int data;
    Node *left;
    Node *right;
    
    Node(int i)
    {
        this->data = i;
        this->left = NULL;
        this->right = NULL;
        cout << "created " << i << endl;
    }

};

class BST
{
    private:
        stack<int> s;
        void destructorHelper(Node *node)
        {
            if (node == NULL)
                return;
            else
                destructorHelper(node->left);
                destructorHelper(node->right);
                delete node;
        }
        
        Node* InsertUtil(Node *node, int i)
        {
            if (node == NULL)
            {
                node = new Node(i);
            }

            else if(i <= node->data)
            {
                node->left = InsertUtil(node->left, i);
            }

            else
                node->right = InsertUtil(node->right, i);

            return node;
        }

        void PrintUtil(Node* node)
        {
            if (node == NULL)
                return;
            else
                PrintUtil(node->left);
                cout << " " << node->data;
                PrintUtil(node->right);
        }

        int FindHeightUtil(Node* node)
        {
            if (node == NULL)
                return 0;
            
            int leftHeight = FindHeightUtil(node->left);
            int rightHeight = FindHeightUtil(node->right);

            return max(leftHeight, rightHeight) + 1;
        }

        void LoTUtil(Node *node)
        {
            if (node == NULL)
                return;
            else
            {
                if(node->left != NULL)
                    cout << ", " << node->left->data;
                if(node->right != NULL)
                    cout << ", " << node->right->data;

                LoTUtil(node->left);
                LoTUtil(node->right);

            }
        }

        void InOrderUtil(Node *node)
        {
            if (node == NULL)
                return;
            
            else
            {
                InOrderUtil(node->left);
                s.push(node->data);
                InOrderUtil(node->right);
            }
        }

        void InOrder()
        {
            if(!s.empty())
            {
                while(!s.empty())
                {
                    s.pop();
                }
            }

            InOrderUtil(this->root);

        }

        Node* FindMinUtil(Node* node)
        {
            if (node == NULL)
                return node;

            Node *current = node;
            while(current->left != NULL)
            {
                current = current->left;
            }

            return current;

        }

        Node* DeleteUtil(Node* node, int i)
        {
            if (node == NULL)
                return node;
            else if (i < node->data)
                node->left = DeleteUtil(node->left, i);
            else if (i > node->data)
                node->right = DeleteUtil(node->right, i);

            else
            {   //Leaf node
                if (node->right == NULL && node->left == NULL)
                {
                    delete node;
                    node = NULL;
                }

                //Only left child
                else if(node->right == NULL)
                {
                    Node* temp = node;
                    node = node->left;
                    delete temp;
                }

                //Only right child
                else if(node->left == NULL)
                {
                    Node* temp = node;
                    node = node->right;
                    delete temp;
                }
                
                //both children, find minimum in right subtree
                else
                {
                    Node *temp = FindMinUtil(node->right);
                    node->data = temp->data;
                    node->right = DeleteUtil(node->right, temp->data);
                }
            }

            return node;
        }


    public:
        Node *root;

        BST()
        {
            this->root = NULL;
        }

        ~BST()
        {
            Node*ptr = this->root;
            destructorHelper(ptr);

            cout << "Deleted BST\n";

        }


        void Insert(int i)
        {   
            if (this->root == NULL)
                this->root = new Node(i);

            else
            {
                this->root = InsertUtil(this->root, i);
            }

        }

        void PrintInOrder()
        {
            PrintUtil(this->root->left);
            cout << " --> " << this->root->data << " <-- ";
            PrintUtil(this->root->right);

            cout << "\n";
        }

        int FindMin()
        {
            Node* ptr = this->root;
            Node *temp;

            while(ptr)
            {
                temp = ptr;
                ptr = ptr->left;
            }

            return temp->data;
        }

        int FindMax()
        {
            Node* ptr = this->root;
            Node *temp;

            while(ptr)
            {
                temp = ptr;
                ptr = ptr->right;
            }

            return temp->data;
        }

        int FindHeight()
        {
            return FindHeightUtil(this->root);
        }

        void LevelOrderTransversal()
        {
            if(this->root == NULL)
            {
                cout << "Empty tree\n";
                return;
            }

            else
            {
                cout << this->root->data;
                LoTUtil(this->root);
                cout << "\n";
            }
        }

        bool isBST()
        {
            InOrder();
            int prev = s.top();
            s.pop();

            while(!s.empty())
            {
                if (prev < s.top())
                    return false;
                else
                {
                    prev = s.top();
                    s.pop();
                }

            }

            return true;
        }

        void Delete(int i)
        {
            if (i == this->root->data)
            {
                cout << "Cannot delete root\n";
                return;
            }

            else
                this->root = DeleteUtil(this->root, i);
        }

};


int main()
{
    BST *bst = new BST;
    bst->Insert(10);
    bst->Insert(12);
    bst->Insert(5);
    bst->Insert(1);
    bst->Insert(15);
    bst->Insert(8);
    bst->Insert(7);
    bst->Insert(9);

    cout << "Inorder Print:";
    bst->PrintInOrder();
    cout << "Min Value: " << bst->FindMin() << endl;
    cout << "Max Value: " << bst->FindMax() << endl;
    cout << "Tree Height: " << bst->FindHeight() <<endl;
    cout << "Level Order Transversal: ";
    bst->LevelOrderTransversal();
    cout << "Is it BST?" << (bst->isBST()? " True\n" : " False\n");

    bst->Delete(8);
    cout << "Inorder Print:";
    bst->PrintInOrder();
    delete bst;
    return 0;
}