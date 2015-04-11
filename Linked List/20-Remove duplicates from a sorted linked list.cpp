#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void removeDuplicateSortedLL(struct node *head)
{
	struct node* temp = head;
	struct node* nextDistinct;
	while((temp!=NULL)&&(temp->next!=NULL))
	{
		if(temp->next->data != temp->data)
		{
			temp = temp->next;
		}
		else
		{
			nextDistinct = temp->next->next;
			while((nextDistinct!=NULL)&&nextDistinct->next!=NULL)
			{
				if(nextDistinct->data==temp->data)
				{
					struct node* previous = nextDistinct;
					nextDistinct = nextDistinct->next;
					free(nextDistinct);
				}
				else
				{
					break;
				}
			}
			temp->next = nextDistinct;
		}
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
	struct node* head= NULL;
	insert(1,&head);
	insert(1,&head);
	insert(1,&head);
	insert(5,&head);
	insert(4,&head);
	insert(3,&head);
	insert(3,&head);
	print(head);
	removeDuplicateSortedLL(head);
	print(head);
	return 0;
}