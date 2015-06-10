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

void swap(struct node** headRef,int k)
{
	int count = 1;
	struct node* curr = *headRef, *node1 = NULL,*node2 = NULL;
	struct node* node1Prev,*node2Prev;
	while(curr!=NULL)
	{
		if(count<k)
		{
			node1Prev = curr;
		}
		else if(count==k)
		{
			node1 = curr;
			node2 = *headRef;
		}
		else if(count>k)
		{
			node2Prev = node2;
			node2 = node2->next;
		}
		count++;
		curr = curr->next;
		
	}
	if((node1!=NULL)&&(node2!=NULL))
	{
		if(node1 == node2)
		{
			
		}
		else if((node1->next != node2)&&(node2->next != node1))
		{
			struct node* node1Next = node1->next;
			node1Prev->next = node2;
			node2Prev->next = node1;
			node1->next = node2->next;
			node2->next = node1Next;
		}
		else if(node1->next == node2)
		{
			node1Prev->next = node2;
			node1->next = node2->next;
			node2->next = node1;
		}
		else if(node2->next == node1)
		{
			node2Prev->next = node1;
			node2->next = node1->next;
			node1->next = node2;
		}
	}
}

int main() {
	struct node* head = NULL;
	
	insert(&head,10);
	insert(&head,20);
	insert(&head,30);
	insert(&head,40);
	insert(&head,50);
	insert(&head,60);
	print(head);
	swap(&head,4);
	print(head);
	
	
	return 0;
}