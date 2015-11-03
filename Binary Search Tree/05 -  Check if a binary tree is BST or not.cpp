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

bool isBST(struct node* root,int min,int max)
{
	if(root == NULL)
	return true;
	
	if((root->key > max) || (root->key < min))
	return false;
	
	bool leftBST = isBST(root->left,min,root->key-1);
	bool rightBST = isBST(root->right,root->key+1,max);
	
	return leftBST&&rightBST;
}

int main() {
	struct node *root = NULL;
    root = insertRecur(root, 50);
    insertRecur(root, 30);
    insertRecur(root, 20);
    insertRecur(root, 40);
    insertRecur(root, 70);
    insertRecur(root, 60);
    insertRecur(root, 80);
    
    root->left->left->key = 100;
    int *s,*p;
    s = new int;
    p = new int;
   // printInOrder(root);
	cout<<isBST(root,INT_MIN,INT_MAX);
	return 0;
}
