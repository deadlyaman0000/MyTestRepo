#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

// Checking wether the Tree is Binary searc tree or not
int isBst(Node *Root)
{
    static Node *prev = NULL;
    if (Root != NULL)
    {
        if (!isBst(Root->left))
        {
            return 0;
        }
        if (prev != NULL && Root->data <= prev->data)
        {
            return 0;
        }
        prev = Root;
            return isBst(Root->right);
            
    }
    else
    {
        return 1;
    }
}

// Creating node function
Node *CreateNode(int data)
{

    Node *n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function for Linking
Node *LinkNode(Node *ptr, Node *Left, Node *Right)
{
    ptr->left = Left;
    ptr->right = Right;
    return ptr;
}

void InOrderTraversal(Node *Root)
{
    if (Root != NULL)
    {
        InOrderTraversal(Root->left);
        cout << Root->data << endl;
        InOrderTraversal(Root->right);
    }
}
int main()
{

    Node *n = CreateNode(50);
    Node *n1 = CreateNode(40);
    Node *n2 = CreateNode(60);
    Node *n3 = CreateNode(20);
    Node *n4 = CreateNode(45);
    Node *n5 = CreateNode(70);
    Node *n6 = CreateNode(55);

    LinkNode(n, n1, n2);
    LinkNode(n1, n3, n4);
    LinkNode(n2, n6, n5);

    InOrderTraversal(n);
    // Checking binary tree
if(isBst(n) ) {
    cout<<"It is Binary Search Tree " <<endl ;
}
else {
    cout<< "It is not Binary Search Tree" <<endl ;
}

    return 0;
}