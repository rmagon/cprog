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

struct node* add(struct node* a,struct node* b, int* carry)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	int myCarry = 0;
	if(a->next != NULL)
	{
	newNode->next = add(a->next,b->next,&myCarry);
	}
	else
	{
		newNode->next = NULL;
	}
	
	
	newNode->a = a->a + b->a + myCarry;
	*carry = (newNode->a)/10;
	newNode->a = (newNode->a)%10;
	
	return newNode;
}

struct node* calculateSum(struct node* a,int sizeA, struct node* b,int sizeB)
{
	int initCarry = 0;
	struct node* sumList = NULL;
	struct node* sumListTail = NULL;
	if(sizeA == sizeB)
	{
		sumList = add(a,b,&initCarry);
		if(initCarry!=0)
		{
			struct node* newNode = (struct node*)malloc(sizeof(struct node));
			newNode->a = initCarry;
			newNode->next = sumList;
			sumList = newNode;
		}
	}
	else
	{
		if(sizeA > sizeB)
		{
			sumList = a;
			sumListTail = a;
			a = a->next;
			int c = 1;
			while(c<(sizeA-sizeB))
			{
				sumListTail->next = a;
				sumListTail = sumListTail->next;
				a = a->next;
				c++;
				
			}
			sumListTail->next = add(a,b,&initCarry);
			if(initCarry!=0)
			{
				struct node* newNode = (struct node*)malloc(sizeof(struct node));
				newNode->a = initCarry;
				newNode->next = sumListTail;
				sumListTail = newNode;
			}
		}
	}
	return sumList;
}

int main() {
	struct node* head = NULL;
	struct node* head1 = NULL;
	insert(&head,1);
	insert(&head,0);
	insert(&head,1);
	insert(&head,1);
	insert(&head,1);
	insert(&head1,3);
	insert(&head1,9);
	insert(&head1,1);
	print(head);
	print(head1);
	struct node* sum = calculateSum(head,5,head1,3);
	print(sum);
	
	
	return 0;
}