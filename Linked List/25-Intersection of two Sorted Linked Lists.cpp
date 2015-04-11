#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

struct node* intersectionOfSortedLists(struct node* head1,struct node* head2)
{
	struct node* tail = NULL;
	struct node* headIntersection = NULL;

	while((head1!=NULL)&&(head2!=NULL))
	{
		if(head1->data == head2->data)
		{
			struct node* newNode = (struct node*)malloc(sizeof(struct node));
			newNode->data = head1->data;
			newNode->next = NULL;
			if(tail==NULL)
			{
				tail = newNode;
			}
			else
			{
				tail->next = newNode;
			}
			if(headIntersection==NULL)
			{
				headIntersection = newNode;
			}
			head1 = head1->next;
			head2 = head2->next;
		}
		else if(head1->data < head2->data)
		{
			head1  = head1->next;
		}
		else //head2->data < head1->data
		{
			head2 = head2->next;
		}
	}
	return headIntersection;
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
	struct node* head2 = NULL;

	insert(7,&head2);
	insert(6,&head2);
	insert(5,&head2);
	insert(4,&head2);


	insert(5,&head);
	insert(4,&head);
	insert(3,&head);
	insert(2,&head);
	print(head);
	print(head2);
	struct node* intersection  = intersectionOfSortedLists(head,head2);
	print(intersection);
	return 0;
}