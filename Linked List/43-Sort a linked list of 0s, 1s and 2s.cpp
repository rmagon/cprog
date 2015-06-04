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

void sort012(struct node* head)
{
	struct node* temp1 = head,*temp2 = head;
	int c0=0,c1=0,c2=0;
	while(temp1)
	{
		if(temp1->a==0)
		c0++;
		else if(temp1->a==1)
		c1++;
		else
		c2++;
		temp1=temp1->next;
	}
	while(temp2)
	{
		if(c0)
		{
			temp2->a = 0;
			c0--;
		}
		else if(c1)
		{
			temp2->a = 1;
			c1--;
		}
		else
		{
			temp2->a = 2;
			c2--;
		}
		temp2 = temp2->next;
	}
}

int main() {
	struct node* head = NULL;
	struct node* head1 = NULL;
	insert(&head,1);
	insert(&head,0);
	insert(&head,1);
	insert(&head,1);
	insert(&head,1);
	insert(&head,2);
	insert(&head,0);
	insert(&head,1);
	print(head);
	sort012(head);
	print(head);
	
	
	return 0;
}