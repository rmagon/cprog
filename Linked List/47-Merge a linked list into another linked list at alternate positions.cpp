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
void merge(struct node** head, struct node** head1)
{
	struct node* curr = *head,*curr1 = *head1;
	
	while(curr!=NULL)
	{
		curr1 = *head1;
		if((*head1)!=NULL)
		{
		*head1 = curr1->next;
		curr1->next = curr->next;
		curr->next = curr1;
		}
		curr =curr->next->next;
	}
}

int main() {
	struct node* head = NULL;
	struct node* head2 = NULL;
	
	insert(&head,10);
	insert(&head,20);
	insert(&head,30);	
	insert(&head,40);
insert(&head2,500);
insert(&head2,600);
insert(&head2,700);
insert(&head2,800);
insert(&head2,900);
merge(&head,&head2);
	print(head);
	print(head2);
	
	
	return 0;
}