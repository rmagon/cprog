#include <iostream>
#include <stack>
using namespace std;
struct node
{
    int data;
    struct node *small,*large;
};


struct node* createNode(int k)
{
    struct node* temp = new node;
    temp->small = NULL;
    temp->large = NULL;
    temp->data = k;
    return temp;
}

int main() {
	struct node* root = createNode(4);
	root->small = createNode(2);
	root->large = createNode(4);
	root->small->small = createNode(1);
	root->small->large = createNode(3);
	root->large->small = createNode(20);
	root->large->large = createNode(30);
	root->small->small->small = createNode(100);
	root->small->small->large = createNode(200);
	root->small->small->large->small = createNode(300);
	root->small->small->large->large = createNode(400);
    stack<struct node*> q1;
    stack<struct node*> q2;
	q1.push(root);
	while((!q1.empty())&&(q2.empty()))
	{
	    while(!q1.empty())
	    {
	    struct node* temp = q1.top();
	    cout<<temp->data<<" ";

	    if(temp->large!=NULL)
	    q2.push(temp->large);
	    if(temp->small!=NULL)
	    q2.push(temp->small);
	   
	    q1.pop();
	    }
	    
	     while(!q2.empty())
	    {
	    struct node* temp = q2.top();
	    cout<<temp->data<<" ";

	    if(temp->small!=NULL)
	    q1.push(temp->small);
	    if(temp->large!=NULL)
	    q1.push(temp->large);
	    
	    q2.pop();
	    }
	}
	return 0;
}
