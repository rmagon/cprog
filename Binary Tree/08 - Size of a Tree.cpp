#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};

int size(struct node* root)
{
    if(root==NULL)
    return 0;
    
    int sizeLeft = size(root->left);
    int sizeRight = size(root->right);
    
    return sizeLeft + sizeRight + 1;
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
	cout<<"Size:"<<size(root);
	cout<<endl;
	return 0;
}
