// Let us traverse the created list and print the data of each node
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void printList(struct node* head)
{
	struct node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main() {
	struct node *head,*second,*third;
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	printList(head);
	return 0;
}