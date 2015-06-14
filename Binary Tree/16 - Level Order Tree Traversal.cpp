#include <iostream>
#include <queue>
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

    	queue<struct node*> q;
	struct node* temp = root;
	while(temp!=NULL)
	{
	    cout<<temp->data<<" ";
	    
	    if(temp->small!=NULL)
	    q.push(temp->small);
	    
	    if(temp->large!=NULL)
	    q.push(temp->large);
	    
	    if(q.empty())
	    temp = NULL;
	    else
	    temp = q.front();
	    
	    q.pop();
	}
	return 0;
}
