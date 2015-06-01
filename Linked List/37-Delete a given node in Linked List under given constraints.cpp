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

void deleteWithConstraints(struct node* head, struct node* del)
{
	if(del==head)
	{
		head->a = head->next->a;
		deleteWithConstraints(head,head->next);
	}
	else
	{
		struct node* back = head;
		while(head != del)
		{
			back = head;
			head = head->next;
		}
		back->next = head->next;
		free(head);
	}
}
int main() {
	struct node* head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);
	print(head);
	deleteWithConstraints(head,head);
	print(head);
	return 0;
}