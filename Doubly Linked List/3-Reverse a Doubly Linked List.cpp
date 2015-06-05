#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

void reverse(struct node** headRef)
{
	struct node* curr = *headRef;
	struct node* follow;
	while(curr!=NULL)
	{
		follow = curr;
		struct node* temp = curr->next;
		curr->next = curr->prev;
		curr->prev = temp;
		curr = curr->prev;
	}
	(*headRef) = follow;
}
void insertBeforeHead(struct node** head,int k)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	temp->data = k;
	if((*head)==NULL)
	{
		*head = temp;
	}
	else
	{
		(*head)->prev = temp;
		temp->next = *head;
		*head = temp;
	}
}

void traverseFront(struct node* curr)
{
	while(curr)
	{
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}

void traverseBack(struct node* curr)
{
	struct node* back = curr;
	while(curr)
	{
		back = curr;
		curr = curr->next;
	}
	while(back)
	{
		cout<<back->data<<" ";
		back = back->prev;
	}
	cout<<endl;
}

int main() {
	struct node* head = NULL;
	insertBeforeHead(&head,10);
	insertBeforeHead(&head,5);
	insertBeforeHead(&head,3);
	insertBeforeHead(&head,2);
	insertBeforeHead(&head,4);
	traverseFront(head);
	traverseBack(head);
	reverse(&head);
		traverseFront(head);
	traverseBack(head);
	return 0;
}