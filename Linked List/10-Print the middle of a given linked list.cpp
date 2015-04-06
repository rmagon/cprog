//Delete in Constant Time (almost)
#include <iostream>
using namespace std;
struct node
{
	int a;
	struct node* next;
};

void printMid(struct node* head)
{
	struct node* turtle = head;
	struct node* rabbit = head;
	while(rabbit!=NULL&&rabbit->next!=NULL)
	{
		rabbit=rabbit->next->next;
		turtle=turtle->next;
	}
	cout<<"Middle Element is "<<turtle->a<<endl;
	
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
	printMid(head);
	return 0;
}