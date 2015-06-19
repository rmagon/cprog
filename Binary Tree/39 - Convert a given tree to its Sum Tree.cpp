#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
    struct node* rightNext;
};

void createSumeTree(struct node* root)
{
    int leftVal = 0, rightVal = 0;
    int newLeftVal = 0, newRightVal = 0;
    
    if(root->left)
    {
        leftVal = root->left->data;
        createSumeTree(root->left);
        newLeftVal = root->left->data;
    }
    
    if(root->right)
    {
        rightVal = root->right->data;
        createSumeTree(root->right);
        newRightVal = root->right->data;
    }
    
    root->data = leftVal + rightVal + newRightVal + newLeftVal;
    
}

void printInOrder(struct node* root)
{
    if(root == NULL)
    return;
    
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

struct node* createNode(int k)
{
    struct node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = k;
    temp->rightNext = NULL;
    return temp;
}


int main() {
	struct node* root = createNode(10);
	root->right = createNode(-2);
	root->left = createNode(6);
	root->left->left = createNode(8);
	root->left->right = createNode(-4);
    root->right->left = createNode(7);
    root->right->right = createNode(5);
    printInOrder(root);
    createSumeTree(root);cout<<endl;
    printInOrder(root);
	
	return 0;
}
