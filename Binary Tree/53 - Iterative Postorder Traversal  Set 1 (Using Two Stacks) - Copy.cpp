#include <iostream>
#include <stack>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};

void printInOrder(struct node* root)
{
    if(root == NULL)
    return;
    
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

void printIterativeInOrder(struct node* root)
{
	stack<struct node*> me;
	
	if(root!=NULL)
	{
		while(root != NULL)
		{
			me.push(root);
			root = root->left;
		}
		
		while(!me.empty())
		{
			
		}
	}
}

void printIterativePreOrder(struct node* root)
{
	stack<struct node*> q;
	q.push(root);
	while(!q.empty())
	{
		struct node* temp = q.top();
		q.pop();
		
		if(temp->right)
		q.push(temp->right);
		
		if(temp->left)
		q.push(temp->left);
		
		cout<<temp->data<<" ";
	}
}

void printIterativePostOrder(struct node* root)
{
	stack<struct node*> s1,s2;
	s1.push(root);
	while(!s1.empty())
	{
		struct node* temp = s1.top();
		s1.pop();
		
		if(temp->left)
		s1.push(temp->left);
		
		if(temp->right)
		s1.push(temp->right);
		
		s2.push(temp);
	}
	
	while(!s2.empty())
	{
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
	
}

void printPreOrder(struct node* root)
{
    if(root == NULL)
    return;
    
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(struct node* root)
{
    if(root==NULL)
    return;
    
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
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
	
	cout<<"Post Order:";
	printPostOrder(root);
	cout<<endl;
	
	cout<<"Iterative Post Order:";
	printIterativePostOrder(root);
	cout<<endl;
	
	cout<<"Pre Order:";
	printPreOrder(root);
	cout<<endl;
	
	cout<<"Iterative Pre Order:";
	printIterativePreOrder(root);
	cout<<endl;
	
	return 0;
}
