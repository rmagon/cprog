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

void mirror(struct node* root)
{
    if(root==NULL)
    return;
    
    mirror(root->left);
    mirror(root->right);
    
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
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
	root->left->right->right = createNode(5);
	printInOrder(root);
	mirror(root);
	cout<<endl;
	printInOrder(root);
	cout<<endl;
	return 0;
}
