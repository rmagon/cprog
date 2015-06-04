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
struct node* pairWiseSwap(struct node** headRef)
{
	struct node* temp = *headRef;
	if((*headRef)->next!=NULL)
	{
		temp = (*headRef)->next;
		struct node* laterList = (*headRef)->next->next;
		(*headRef)->next->next = (*headRef);
		(*headRef)->next = (*headRef);
		if(laterList!=NULL)
		(*headRef)->next=pairWiseSwap(&laterList);
		else
		(*headRef)->next = NULL;
	}
	return temp;
}

int main() {
	struct node* head = NULL;
	
	insert(&head,10);
	insert(&head,20);
	insert(&head,30);	
	insert(&head,40);
	struct node* newList = pairWiseSwap(&head);
	print(newList);
	
	return 0;
}