#include <iostream>
using namespace std;

struct node
{
	int a;
	struct node* next;
};

void insert(struct node** head,int data)
{
	struct node* looper = *head;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->a = data;
	temp->next = NULL;
	if((*head) == NULL)
	{
		(*head) = temp;
		return;
	}
	else
	{
		while(looper->next!=NULL)
		{
			looper = looper->next;
		}
		looper->next = temp;
		return;
	}
}

void print(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d ",head->a);
		head = head->next;
	}
	printf("\n");
}

void rotate(struct node** headRef, int k)
{
	if(k==0)
	return;
	int count=1;
	struct node* last;
	struct node* kth;
	struct node* temp = *headRef;
	while(temp!=NULL)
	{
		if(count==k)
		{
			kth = temp;
		}
		count++;
		last = temp;
		temp = temp->next;
	}
	struct node* headNew = kth->next;
	kth->next = NULL;
	last->next = *headRef;
	*headRef = headNew;
}
int main() {
	struct node* head = NULL;
	
	insert(&head,10);
	insert(&head,20);
	insert(&head,30);
	insert(&head,40);
insert(&head,50);
insert(&head,60);
rotate(&head,4);
	print(head);
	
	
	return 0;
}