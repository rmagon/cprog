#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void printReverse(struct node *head)
{
	if(head==NULL)
	return;
	printReverse(head->next);
	cout<<head->data<<" ";
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
	struct node* head= NULL;

	insert(5,&head);
	insert(6,&head);
	insert(4,&head);
	insert(3,&head);
	print(head);
	printReverse(head);
	return 0;
}