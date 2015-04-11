#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void deleteAlternateNodes(struct node* head)
{
	while((head!=NULL)&&(head->next!=NULL))
	{
		struct node* toDelete = head->next;
		head->next = head->next->next;
		free(toDelete);
		head = head->next;
	}
}

void deleteAlternateNodeRecusrive(struct node** head)
{
	if(((*head)!=NULL)&&((*head)->next!=NULL))
	{
		struct node* toDelete = (*head)->next;
		(*head)->next = (*head)->next->next;
		free(toDelete);
		deleteAlternateNodeRecusrive(&(*head)->next);
	}
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
	insert(8,&head);
	insert(7,&head);
	insert(6,&head);
	insert(5,&head);
	insert(4,&head);


	insert(5,&head);
	insert(4,&head);
	insert(3,&head);
	insert(2,&head);
	print(head);

	 deleteAlternateNodeRecusrive(&head);
	print(head);
	return 0;
}