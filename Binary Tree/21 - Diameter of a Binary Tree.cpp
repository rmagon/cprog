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

int diameter(struct node* root, int* h)
{
    if(root==NULL)
    {
        (*h) = 0;
        return 0;
    }
    
    int leftH,rightH;
    
    int leftDia = diameter(root->left,&leftH);  
    int rightDia = diameter(root->right,&rightH);
    
    (*h) = max(leftH,rightH) + 1;
        
    return max(leftH+rightH+1,max(leftDia,rightDia));
}

int main() {
	struct node* root = createNode(50);
	root->left = createNode(7);
	root->right = createNode(2);
//	root->left->left = createNode(3);
//	root->left->right = createNode(5);
	root->right->left = createNode(1);
	root->right->right = createNode(30);
	root->right->right->right = createNode(40);
	root->right->left->left = createNode(10);
	root->right->left->left->left = createNode(12);
    int h = 0;
    int i = diameter(root,&h);
	cout<<"diameter "<<i;
	return 0;
}
