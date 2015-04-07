//Delete in Constant Time (almost)
#include <iostream>
using namespace std;
struct node
{
	int a;
	struct node* next;
};

void reverse(struct node** headRef)
{
	struct node* prev = NULL;
	struct node* cur = *headRef;
	struct node* next;
	while(cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*headRef = prev;
}

void push(int data,struct node** headRef)
{
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->a = data;
	temp->next = *headRef;
	*headRef = temp;
}

void print(struct node* head)
{
	struct node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->a<<" ";
		temp = temp->next;
	}
}
int main() {
	// your code goes here
	struct node* head;
	push(1,&head);
	push(2,&head);
	push(17,&head);
	push(18,&head);
	push(20,&head);
	push(27,&head);
	print(head);
	cout<<endl;
	reverse(&head);
	print(head);
	return 0;
}