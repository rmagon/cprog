#include <iostream>
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

bool checkFoldable(struct node* child1,struct node* child2)
{
    if((child1==NULL)&&(child2!=NULL))
    return false;
    else if((child2==NULL)&&(child1!=NULL))
    return false;
    else if((child1==NULL)&&(child2==NULL))
    return true;
    
    /*if((child1->left != NULL)&&(child2->right==NULL)
    {
        return false;
    }
    else if((child1->right!=NULL)&&(child2->left==NULL))
    {
        return false;
    }
    else
    {*/
        return checkFoldable(child1->right,child2->left) && checkFoldable(child1->left,child2->right);
   // }
}

bool foldable(struct node* root)
{
    bool ok = false;

    if((root->left==NULL)&&(root->right==NULL))
    {
        ok = true;
    }
    else if((root->left!=NULL)&&(root->right != NULL))
    {
        ok = true;
    }

    if(ok == true)
    {
        return checkFoldable(root->left,root->right);
    }
    else
    {
        return false;
    }
    
}
int main() {
	struct node* root = createNode(1);
	
	root->right = createNode(3);
	root->right->right = createNode(10);
	
	root->left = createNode(2);
	root->left->left = createNode(300);
	
	root->left->right = createNode(20);
//	root->left->left = createNode(4);
//	root->left->right = createNode(5);
	
	
	cout<<foldable(root);
	
	return 0;
}
