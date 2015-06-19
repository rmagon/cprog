#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
    struct node* inOrderSucc;
};

void assignInOrder(struct node* root)
{
    static struct node* prev = NULL;
    if(root == NULL)
    return;
    
    assignInOrder(root->right);
    root->inOrderSucc = prev;
    prev = root;
    assignInOrder(root->left);
    
    
}

struct node* createNode(int k)
{
    struct node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = k;
    temp->inOrderSucc = NULL;
    return temp;
}

void traverse(struct node* start)
{
    while(start!=NULL)
    {
        cout<<start->data<<" ";
        start = start->inOrderSucc;
    }
}

void printInOrder(struct node* root)
{
    if(root == NULL)
    return;
    
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}
int main() {
	struct node* root = createNode(10);
	root->right = createNode(2);
	root->left = createNode(6);
	root->left->left = createNode(8);
	root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(5);
    
    printInOrder(root);
    assignInOrder(root);cout<<endl;
    traverse(root->left->left);
	
	return 0;
}
