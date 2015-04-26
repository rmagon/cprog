#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void separateEvenOdd(struct node** head)
{
	struct node* prev = NULL;
	struct node* temp = *head;
	struct node* oddHEAD = NULL;
	struct node* oddTAIL = NULL;
	
	while(temp!=NULL)
	{
		if(temp->data%2!=0)
		{
			if(oddHEAD == NULL)
			{
				oddHEAD = temp;
				oddTAIL = temp;
			}
			else
			{
				oddTAIL->next = temp;
				oddTAIL = temp;
			}
			temp = temp->next;
			oddTAIL->next =NULL;
			if(prev!=NULL)
			{
				prev->next = temp;
			}
			else
			{
				*head = temp;
			}
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
	
	prev->next = oddHEAD;
	
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
	
	insert(6,&head);
	insert(7,&head);
	insert(1,&head);
	insert(4,&head);
	insert(5,&head);
	insert(10,&head);
	insert(12,&head);
	insert(8,&head);
	insert(15,&head);
	insert(17,&head);
	
	print(head);
	separateEvenOdd(&head);
	print(head);
	return 0;
}