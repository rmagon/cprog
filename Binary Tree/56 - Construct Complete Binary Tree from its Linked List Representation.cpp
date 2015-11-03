#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct list
{
	int data;
	struct list* next;
};
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

 struct list* createListNode(int k)
 {
	struct list* temp = new list; 	
	temp->data = k;
	temp->next = NULL;
	return temp;
}

struct node* toTreeNode(struct list* listNode)
{
	struct node* n = new node;
	n->data = listNode->data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

struct node* createTree(struct list* listHead)
{
	queue<struct node*> q;
	q.push(toTreeNode(listHead));
	struct node* master = q.front();
	while(!q.empty())
	{
		struct node* root = q.front();
		q.pop();
		if(listHead->next)
		{
			root->left = toTreeNode(listHead->next);
			listHead = listHead->next;
			if(listHead->next)
			{
				root->right = toTreeNode(listHead->next);
				listHead = listHead->next;
			}
		}
		
		if(root->left != NULL)
		q.push(root->left);
		
		if(root->right != NULL)
		q.push(root->right);
	}
	return master;
}

void printInOrder(struct node* root)
{
    if(root == NULL)
    return;
    
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

int main() {
	list* listHead = createListNode(1);
	listHead->next = createListNode(2);
	listHead->next->next = createListNode(3);
	listHead->next->next->next = createListNode(4);
	listHead->next->next->next->next = createListNode(5);	
	listHead->next->next->next->next->next = createListNode(6);
	
	struct node* root = createTree(listHead);
	printInOrder(root);
	return 0;
}