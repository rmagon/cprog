#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};

bool same(struct node* root,struct node* root2)
{
    if(root==NULL&&root2==NULL)
    return true;
    else if(root!=NULL&&root2!=NULL&&(root->data == root2->data))
    {
        bool sameLeft = same(root->left,root2->left);
        bool sameRight = same(root->right,root2->right);
        return sameLeft && sameRight;
    }
    else
    {
        return false;
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
	
	struct node* root2 = createNode(1);
	root2->right = createNode(3);
	root2->left = createNode(2);

	root2->left->right = createNode(5);
	
	cout<<"Same:"<<(same(root,root2) ? "Yes" : "No");
	cout<<endl;
	return 0;
}
