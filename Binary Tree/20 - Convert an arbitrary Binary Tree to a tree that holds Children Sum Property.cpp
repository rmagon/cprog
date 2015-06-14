#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};

void Increment(struct node* root,int diff)
{
    if(root==NULL)
    return;
    
    
    root->data = root->data + diff;
    if(root->left != NULL)
    {
        Increment(root->left,diff);
    }
    else if(root->right != NULL)
    {
        Increment(root->right,diff);
    }
}

void convertToChildSum(struct node* root)
{
    if(root==NULL)
    return;
    
    if((root->left==NULL)&&(root->right==NULL))
    return;
    
    int left=0,right=0;
    convertToChildSum(root->left);
    convertToChildSum(root->right);
    
    if(root->left != NULL)
    left = root->left->data;
    
    if(root->right!=NULL)
    right = root->right->data;
    
    int childSum = left+right;
    
    int diff = childSum - root->data;
    
    if(diff>0)
    root->data = root->data + diff;
    else
    {
        Increment(root->left,-diff);
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
void printPostOrder(struct node* root)
{
    if(root==NULL)
    return;
    
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

int main() {
	struct node* root = createNode(50);
	root->left = createNode(7);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->left->right = createNode(5);
	root->right->left = createNode(1);
	root->right->right = createNode(30);	

    convertToChildSum(root);
	printPostOrder(root);
	return 0;
}
