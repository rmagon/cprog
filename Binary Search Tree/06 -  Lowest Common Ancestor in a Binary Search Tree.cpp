#include <iostream>
#include <climits>
using namespace std;
struct node
{
    int key;
    struct node* left,*right;
};

struct node* createNode(int k)
{
    struct node* no = new node;
    no->key = k;
    no->left = NULL;
    no->right = NULL;
    return no;
}

struct node* insertRecur(struct node* root, int k)
{
    if(root==NULL)
    return createNode(k);
    
    if(root->key>k)
    root->left = insertRecur(root->left,k);
    else
    root->right = insertRecur(root->right,k);
    
    return root;
}

void printInOrder(struct node* root)
{
    if(root == NULL)
    return;
    
    printInOrder(root->left);
    cout<<root->key<<" ";
    printInOrder(root->right);
}

int lca(struct node* root,int val1,int val2)
{
	if(root == NULL)
	return -1;
	
	if((root->key > val1)&&(root->key > val2))
	{
		return lca(root->left,val1,val2);
	}
	else if((root->key < val1)&&(root->key < val2))
	{
		return lca(root->right,val1,val2);
	}
	else if((root->key <= val1)&&(root->key >= val2))
	{
		return root->key;
	}
	else if((root->key >= val1)&&(root->key <= val2))
	{
		return root->key;
	}
	return -1;
}

int main() {
	struct node *root = NULL;
    root = insertRecur(root, 20);
    insertRecur(root, 8);
    insertRecur(root, 22);
    insertRecur(root, 4);
    insertRecur(root, 12);
    insertRecur(root, 10);
    insertRecur(root, 14);
    
    root->left->left->key = 100;
    int *s,*p;
    s = new int;
    p = new int;
   // printInOrder(root);
	cout<<lca(root,10,14)<<endl;
	cout<<lca(root,14,8)<<endl;
	cout<<lca(root,10,22)<<endl;
	return 0;
}
