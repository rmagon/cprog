#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

void insertBeforeNode(struct node* beforeThis, int k)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = k;
	temp->prev = beforeThis->prev;
	temp->next = beforeThis;
	beforeThis->prev->next = temp;
	beforeThis->prev = temp;
}
void insertAfterNode(struct node* afterThis,int k)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = afterThis;
	temp->next = afterThis->next;
	if(afterThis->next !=NULL)
	{
	afterThis->next->prev = temp;
	}
	afterThis->next = temp;
	temp->data = k;
	
}
void insertAtEnd(struct node** head,int k)
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
		struct node* curr = *head;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
		temp->prev = curr;
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
	insertBeforeHead(&head,1);
	insertAtEnd(&head,100);
	insertAfterNode(head->next,555);
	insertBeforeNode(head->next,111);
	insertAfterNode(head->next->next->next->next->next,123);
	traverseFront(head);
	traverseBack(head);
	return 0;
}