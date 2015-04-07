//Find Loop using Rabbit & hare
#include <iostream>
using namespace std;
struct node
{
	int a;
	struct node* next;
};

void findLoop(struct node* headRef)
{
	struct node* rabbit = headRef;
	struct node* hare = headRef;
	
	while(hare!=NULL&&rabbit!=NULL&&rabbit->next!=NULL)
	{
		hare = hare->next;
		rabbit = rabbit->next->next;
		if(hare==rabbit)
		{
			cout<<"LOOP FOUND!"<<endl;
			return;
		}
	}
	cout<<"NO LOOP FOUND"<<endl;
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
	head->next->next->next = head;
	//print(head);
	cout<<endl;
	findLoop(head);
	//print(head);
	return 0;
}