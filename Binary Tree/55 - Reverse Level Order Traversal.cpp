#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node
{
	int data;
	struct node* left,*right;
};

struct node* createNode(int k)
{
	struct node* noo = new node;
	noo->left = NULL;
	noo->right = NULL;
	noo->data = k;
	return noo;
}

void levelOrder(struct node* root)
{
	queue<struct node*> q;
	stack<struct node*> s;
	q.push(root);
	while(!q.empty())
	{
		struct node* temp = q.front();
		s.push(q.front());
		
		q.pop();
		
		if(temp->right)
		q.push(temp->right);
		
		if(temp->left)
		q.push(temp->left);
		
		
		
	}
	
	while(!s.empty())
	{
		cout<<s.top()->data<<" ";
		s.pop();
	}
}

int main() {
	node* root = createNode(3);
	root->left = createNode(4);
	root->right = createNode(5);
	root->left->left = createNode(6);
	root->left->right = createNode(7);
	root->right->right = createNode(78);
	
	levelOrder(root);
	return 0;
}