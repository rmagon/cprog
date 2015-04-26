#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void deleteGreaterRight(struct node** head)
{
	struct node* back = NULL;
	struct node* prev = *head;
	while(prev->next!=NULL)
	{
		if(prev->data < prev->next->data)
		{
			struct node* temp = prev;
			prev = prev->next;
			
			if(temp == *head)
			{
				*head = prev;
			}
			else
			{
				back->next = prev;
			}
			free(temp);
		}
		else
		{
			back = prev;
			prev = prev->next;
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
	struct node* head = NULL;
/*	insert(3,&head);
	insert(2,&head);
	insert(6,&head);
	insert(5,&head);
	insert(11,&head);
	insert(10,&head);
	insert(15,&head);
	insert(12,&head);*/
	
/*	insert(10,&head);
	insert(30,&head);
	insert(40,&head);
	insert(50,&head);
	insert(60,&head);*/
	
	insert(60,&head);
	insert(50,&head);
	insert(40,&head);
	insert(30,&head);
	insert(10,&head);
	
	print(head);
	deleteGreaterRight(&head);
	print(head);
	return 0;
}