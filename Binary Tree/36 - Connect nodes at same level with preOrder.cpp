#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
    struct node* rightNext;
};

void assignPointer(struct node* root)
{
    if(!root)
    return;
    
    if((root->left != NULL)&&(root->right!=NULL))
    root->left->rightNext = root->right;
    
    if((root->right!=NULL)&&(root->rightNext!=NULL)&&(root->rightNext->left!=NULL))
    root->right->rightNext = root->rightNext->left;
    
    
}
void LevelOrder(struct node* a)
{
    if(!a)
    return;
    
    assignPointer(a);
    
    LevelOrder(a->left);
    LevelOrder(a->right);
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

void traverse(struct node* start)
{
    while(start!=NULL)
    {
        cout<<start->data;
        start = start->rightNext;
    }
}
int main() {
	struct node* root = createNode(1);
	root->right = createNode(3);
	root->left = createNode(2);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
    root->right->left = createNode(6);
    LevelOrder(root);
	
	cout<<endl<<"Level One ";
	traverse(root->left);
	
	cout<<endl<<"Level Two ";
	traverse(root->left->left);
	
	return 0;
}
