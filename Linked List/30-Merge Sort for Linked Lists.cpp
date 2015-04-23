#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void splitIntoTwo(struct node* head,struct node** frontRef,struct node** backRef)
{
	if((head==NULL)||(head->next==NULL))
	{
		*frontRef = head;
		*backRef = NULL;
	}
	else
	{
		struct node* fast = head->next;
		struct node* slow = head;
		while(fast!=NULL)
		{
			fast = fast->next;
			if(fast!=NULL)
			{
				fast=fast->next;
				slow=slow->next;
			}
		}
	//	cout<<slow->data;
		*frontRef = head;
		*backRef = slow->next;
		slow->next = NULL;
	}
}

struct node* sortedMerge(struct node* a,struct node* b)
{
	struct node* result = NULL;
	if(a==NULL)
	return b;
	else if(b==NULL)
	return a;
	
	if(a->data < b->data)
	{
		result = a;
		result->next = sortedMerge(a->next,b);
	}
	else
	{
		result = b;
		result->next = sortedMerge(a,b->next);
	}
	return(result);
}

void mergeSort(struct node** headReference)
{
	struct node* head = *headReference;
	struct node* a;
	struct node* b;
	
	if((head==NULL)||(head->next==NULL))
	{
		return;
	}
	
	splitIntoTwo(*headReference,&a,&b);
	
	mergeSort(&a);
	mergeSort(&b);
	
	*headReference = sortedMerge(a,b);
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
	struct node* head = NULL;
	insert(2,&head);
	insert(7,&head);
	insert(6,&head);
	insert(5,&head);
	insert(4,&head);
	insert(5,&head);
	insert(4,&head);
	insert(3,&head);
	insert(100,&head);
	print(head);
	mergeSort(&head);
	print(head);
	return 0;
}