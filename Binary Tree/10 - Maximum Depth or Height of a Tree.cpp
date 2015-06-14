#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};

int height(struct node* root)
{
    if(root == NULL)
    return 0;
    
    int leftH = height(root->left);
    int rightH = height(root->right);
    
    if(leftH > rightH)
    {
        return 1+leftH;
    }
    else
    {
        return 1+rightH;
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
	root->left->right->right = createNode(5);
	cout<<"Hieght of the tree is :"<<height(root);
	cout<<endl;
	return 0;
}
