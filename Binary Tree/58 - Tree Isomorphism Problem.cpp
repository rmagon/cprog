#include <iostream>
using namespace std;

struct node
{
	int k;
	struct node* left, *right;
};

bool isIsomorphic(struct node* n1, struct node* n2)
{
	if((n1==NULL)&&(n2==NULL))
	{
		return true;
	}
	else if((n1==NULL)||(n2==NULL))
	{
		return false;
	}
	else if(n1->k == n2->k)
	{
		return (isIsomorphic(n1->left,n2->left)||isIsomorphic(n1->left,n2->right))&&(isIsomorphic(n1->right,n2->right)||isIsomorphic(n1->right,n2->left));
	}
	else
	{
		return false;
	}
}

struct node* newNode(int l)
{
	struct node* k = new node;
	k->k = l;
	k->left = NULL;
	k->right = NULL;
	return k;
}

int main() {
	struct node *n1 = newNode(1);
    n1->left        = newNode(2);
    n1->right       = newNode(3);
    n1->left->left  = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left  = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);
 
    struct node *n2 = newNode(1);
    n2->left         = newNode(3);
    n2->right        = newNode(2);
    n2->right->left   = newNode(4);
    n2->right->right   = newNode(5);
    n2->left->right   = newNode(6);
    n2->right->right->left = newNode(8);
    n2->right->right->right = newNode(7);
    
    if(isIsomorphic(n1,n2) == true)
    {
    	cout<< "Yes";
    }
    else
    {
    	cout<< "No";
    }
	return 0;
}