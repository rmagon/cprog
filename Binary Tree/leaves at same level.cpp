#include <iostream>
using namespace std;

struct node
{
	int k;
	struct node* left, *right;
};

bool sameLevelLeaves(struct node* n1,int* h)
{
	if(n1==NULL)
	{
		(*h) = 0;
		return true;
	}
	if((n1->left==NULL)&&(n1->right==NULL))
	{
		(*h) = 0;
		return true;
	}
	
	int lh=0,rh=0;

	bool lSame = sameLevelLeaves(n1->left,&lh);
	
	bool rSame = sameLevelLeaves(n1->right,&rh);
	
	if(!lSame)
	{
		cout<<"Returning False !lSame "<<n1->k;
		return false;
	}
	
	if(!rSame)
	{
		cout<<"Returning False !rSame "<<n1->k;
	return false;
	}
	
	if((n1->left)&&(n1->right)&&(lh!=rh))
	{
	cout<<"Returning False lh!=rh "<<n1->k;
	return false;
	}
	
	//if(n1->left)
//	if(n1->left)
	(*h) = max(lh,rh)+1;
//	else if(n1->left)
//	(*h) = rh+1;
//	
	return true;
	
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
	struct node *root = newNode(12);
	root->right = newNode(100);
	root->right->right = newNode(5);
	root->right->right->right = newNode(104);
	
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(99);
	
	int h=0;
    if(sameLevelLeaves(root,&h) == true)
    {
    	cout<< "Yes";
    }
    else
    {
    	cout<< "No";
    }
	return 0;
}