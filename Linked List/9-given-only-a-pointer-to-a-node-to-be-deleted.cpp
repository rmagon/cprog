//Delete in Constant Time (almost)
#include <iostream>
using namespace std;
struct node
{
	int a;
	struct node* next;
};

void push(int data,struct node** headRef)
{
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->a = data;
	temp->next = *headRef;
	*headRef = temp;
}

void insertBeforeHead(int a,struct node** headReference)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->a = a;
	temp->next= *headReference;
	*headReference = temp;
}

void deleteThis(struct node* toDelete)
{
	if(toDelete->next!=NULL)
	{
		toDelete->a = toDelete->next->a;
		struct node* temp = toDelete->next;
		toDelete->next= toDelete->next->next;
		free(temp);
	}
}
void print(struct node* head)
{
	struct node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->a<<" ";
		temp = temp->next;
	}
}
int main() {
	// your code goes here
	struct node* head;
	push(1,&head);
	push(2,&head);
	push(6,&head);
	push(20,&head);
	print(head);
	deleteThis(head->next);
	cout<<"\nafter deleting\n";
	print(head);
	return 0;
}