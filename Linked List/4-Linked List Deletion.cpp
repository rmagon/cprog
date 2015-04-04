// Delete the node with a given key (data in our case)
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void deleteAtPosition(int key, struct node** headReference)
{
	struct node* back = *headReference;
	struct node* temp = *headReference;
	if((*headReference)->data==key)
	{
		*headReference = (*headReference)->next;
	}
	else
	{
	while(temp!=NULL)
	{
		if(temp->data == key)
		{
			back->next = temp->next;
		}
		back = temp;
		temp = temp->next;
	}
	}
}
void insertBeforeHead(int a,struct node** headReference)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->next= *headReference;
	*headReference = temp;
}

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
	struct node *head;
	head = NULL;
	insertBeforeHead(5,&head);
	insertBeforeHead(6,&head);
	insertBeforeHead(7,&head);
	printList(head);
	deleteAtPosition(7,&head);
	cout<<endl;
	printList(head);
	return 0;
}