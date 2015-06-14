#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};

struct node* createNode(int k)
{
    struct node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = k;
    return temp;
}

bool balanced(struct node* root, int* h)
{
    if(root==NULL)
    {
        (*h) = 0;
        return true;
    }
    
    int lefth,righth;
    bool left = balanced(root->left,&lefth);
    bool right = balanced(root->right,&righth);
    
    int diff = righth - lefth;
    (*h) = max(righth,lefth) + 1;
    if ((diff>1)||(diff<-1))
    {
        return false;
    }
    else
    {
        return left && right;
    }
}

int main() {
	struct node* root = createNode(50);
	root->left = createNode(7);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->left->right = createNode(5);
	root->right->left = createNode(1);
	root->right->right = createNode(30);
	root->right->right->right = createNode(40);
	root->right->left->left = createNode(10);
	root->right->left->left->left = createNode(12);
    int h = 0;
    bool i = balanced(root,&h);
	cout<<"balanced "<<i;
	return 0;
}
