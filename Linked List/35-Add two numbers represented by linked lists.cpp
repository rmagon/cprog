#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void insertAtTail(struct node** head,struct node** tail, int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if(*head==NULL)
	{
		*head = temp;
		*tail = temp;
	}
	else
	{
		(*tail)->next = temp;
		*tail = temp;
	}
	temp->next = NULL;
	
}
struct node* addNumbers(struct node* headOne,struct node* headTwo)
{
	struct node* sumHead = NULL;
	struct node* sumTail = NULL;
	int carry = 0;
	while((headOne!=NULL)||(headTwo!=NULL)||(carry!=0))
	{
		if((headOne == NULL) && (headTwo == NULL) && carry!=0)
		{
			int value = carry;
			carry = value/10;
			value = value%10;
			insertAtTail(&sumHead,&sumTail,value);	
		}
		else if(headOne == NULL)
		{
			int value = headTwo->data + carry;
			carry = value/10;
			value = value%10;
			insertAtTail(&sumHead,&sumTail,value);
			headTwo = headTwo->next;
		}
		else if(headTwo == NULL)
		{
			int value = headOne->data + carry;
			carry = value/10;
			value = value%10;
			insertAtTail(&sumHead,&sumTail,value);
			headOne = headOne->next;
		}
		else 
		{
			int value = headOne->data + headTwo->data + carry;
			carry = value/10;
			value = value%10;
			insertAtTail(&sumHead,&sumTail,value);
			headTwo = headTwo->next;
			headOne = headOne->next;
		}
	}
	return sumHead;
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
	struct node* tail = NULL;
	struct node* headTwo = NULL;
	insertAtTail(&head,&tail,9);
	insertAtTail(&head,&tail,9);
	insertAtTail(&head,&tail,9);
	insert(9,&headTwo);
	insert(9,&headTwo);
	insert(9,&headTwo);
	
	print(head);
	print(headTwo);
	struct node* sum = addNumbers(head,headTwo);
	print(sum);
	return 0;
}