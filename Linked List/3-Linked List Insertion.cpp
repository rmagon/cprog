// Three types of Inserts in a Linked List
// 1. Before Head
// 2. After End
// 3. After a specific node
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void insertBeforeHead(int a,struct node** headReference)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->next= *headReference;
	*headReference = temp;
}

void insertAtEnd(int a,struct node** headReference)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->next = NULL;
	struct node* temp2 = *headReference;
	if(temp2==NULL)
	{
		*headReference = temp;
	}
	else
	{
	while(temp2->next!=NULL)
	{
		temp2=temp2->next;
	}
	temp2->next = temp;
	}
}

void insertAfterNode(int a,struct node* afterThis)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->next = NULL;
	if(afterThis->next==NULL)
	{
		afterThis->next = temp;
	}
	else
	{
		temp->next = afterThis->next;
		afterThis->next = temp;
	}
}
void printList(struct node* head)
{
	struct node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main() {
	struct node *head;
	head = NULL;
	insertAtEnd(100,&head);
	insertBeforeHead(5,&head);
	insertBeforeHead(6,&head);
	insertBeforeHead(7,&head);
	insertAfterNode(20,head->next);
	insertAtEnd(500,&head);
	printList(head);
	return 0;
}