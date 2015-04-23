#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

struct node* reverseLinkedList(struct node* head, int k)
{
	int i=0;
	struct node* forward = head;
	struct node* prev = NULL;
	struct node* curr = NULL;
	
	while((forward!=NULL)&&(i<k))
	{
		i++;
		curr = forward;
		forward = forward->next;
		curr->next = prev;
		prev = curr;
	}
	if(forward!=NULL)
	head->next = reverseLinkedList(forward,k);
	return(curr);
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
	insert(1,&head);
	insert(2,&head);
	insert(3,&head);
	insert(4,&head);
	insert(5,&head);
	insert(6,&head);
	insert(7,&head);
	insert(8,&head);
	insert(9,&head);
	insert(10,&head);
	print(head);
	head = reverseLinkedList(head,4);
	print(head);
	int a;
	cin>>a;
	return 0;
}