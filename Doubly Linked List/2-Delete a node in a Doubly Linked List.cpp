#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

void deleteNode(struct node** headRef,struct node* del)
{
	if(del==(*headRef))
	{
		(*headRef) = del->next;
		free(del);
	}
	else
	{
		del->prev->next = del->next;
		del->next->prev = del->prev;
		free(del);
	}
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
	deleteNode(&head,head->next);
		traverseFront(head);
	traverseBack(head);
	return 0;
}