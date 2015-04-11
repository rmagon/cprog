#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void moveLastToFirst(struct node** headRef)
{
	struct node* temp = *headRef;
	struct node* prev;
	while(temp->next!=NULL)
	{
		prev = temp;
		temp = temp ->next;
	}
	prev->next = NULL;
	temp->next=*headRef;
	*headRef = temp;
}

void insert(int data, struct node** head)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->next = *head;
	temp->data = data;
	*head = temp;
}



void print(struct node* head)
{
	struct node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main() {
	// your code goes here
	struct node* head= NULL;
	insert(7,&head);
	insert(1,&head);
	insert(6,&head);
	insert(1,&head);
	insert(5,&head);
	insert(4,&head);
	insert(2,&head);
	insert(3,&head);
	print(head);
	moveLastToFirst(&head);
	print(head);
	return 0;
}