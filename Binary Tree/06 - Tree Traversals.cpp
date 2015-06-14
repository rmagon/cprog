#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};

void printInOrder(struct node* root)
{
    if(root == NULL)
    return;
    
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

void printPreOrder(struct node* root)
{
    if(root == NULL)
    return;
    
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(struct node* root)
{
    if(root==NULL)
    return;
    
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

struct node* createNode(int k)
{
    struct node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = k;
    return temp;
}
int main() {
	struct node* root = createNode(1);
	root->right = createNode(3);
	root->left = createNode(2);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	
	cout<<"In Order:";
	printInOrder(root);
	cout<<endl;
	
	cout<<"Pre Order:";
	printPreOrder(root);
	cout<<endl;
	
	cout<<"Post Order:";
	printPostOrder(root);
	cout<<endl;
	
	return 0;
}
