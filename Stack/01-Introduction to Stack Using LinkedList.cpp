#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void push(struct node** stackHead,int k)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->next = *stackHead;
	*stackHead = temp;
	temp->data = k;
}

int pop(struct node** stackHead)
{
	struct node* temp = *stackHead;
	if(temp==NULL)
	{
	cout<<"underflow ";
	return -999;
	}
	else
	{
		*stackHead = (*stackHead)->next;
		return temp->data;
	}
}

int main() {
	// your code goes here
	struct node* stack = NULL;
	push(&stack,1);
	push(&stack,2);
	push(&stack,5);
	cout<<"pop = "<<pop(&stack)<<endl;
	cout<<"pop = "<<pop(&stack)<<endl;
	cout<<"pop = "<<pop(&stack)<<endl;
	cout<<"pop = "<<pop(&stack)<<endl;
	return 0;
}