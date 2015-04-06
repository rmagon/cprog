//Counting length using recusrion
#include <iostream>
using namespace std;
struct node
{
	int a;
	struct node* next;
};

int calLen(struct node *head)
{
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + calLen(head->next);
	}
}
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
	push(2,&head);
	print(head);
	cout<<endl;
	cout<<calLen(head);
	return 0;
}