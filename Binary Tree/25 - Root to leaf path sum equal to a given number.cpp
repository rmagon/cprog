#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* left,*right;
};

bool rootToLeaf(struct node* current,int left)
{
    if((current->left==NULL)&&(current->right==NULL))
    {
        if(current->data - left == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(current->left==NULL)
    {
        return rootToLeaf(current->right,left-current->data);
    }
    else if(current->right == NULL)
    {
            return rootToLeaf(current->left,left-current->data);
    }
    else
    {
        return rootToLeaf(current->right,left-current->data) || rootToLeaf(current->left,left-current->data);
    }
    
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
	cout<<"Path Exisits:"<<rootToLeaf(root,40);
	return 0;
}
