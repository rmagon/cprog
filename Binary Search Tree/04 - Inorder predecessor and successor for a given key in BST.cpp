#include <iostream>
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

void findSuccPred(struct node* root,int* succ,int* pred,int key)
{
	if(root==NULL)
	return;
	
	if(root->key == key)
	{
		struct node* temp = root->left;
		if(temp!=NULL)
		{
			while(temp->right!=NULL)
			{
				temp = temp->right;
			}
			*pred = temp->key;
		}
		
		temp = root->right;
		if(temp!=NULL)
		{
			while(temp->left!=NULL)
			{
				temp = temp->left;
			}
			*succ = temp->key;
		}
	}
	else if(root->key > key)
	{
		*succ = root->key;
		findSuccPred(root->left,succ,pred,key);
	}
	else if(root->key < key)
	{
		*pred = root->key;
		findSuccPred(root->right,succ,pred,key);
	}
	
	return;
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
    
    int *s,*p;
    s = new int;
    p = new int;
    printInOrder(root);
	findSuccPred(root,s,p,78);
	cout<<"Inorder Successor: "<<*s<<endl<<"Inorder Predecsor: "<<*p;
	return 0;
}
