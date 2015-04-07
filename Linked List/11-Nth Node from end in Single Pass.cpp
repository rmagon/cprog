//Find Nth Node from end in Single Pass
#include <iostream>
using namespace std;
struct node
{
	int a;
	struct node* next;
};

void printNthFromEnd(int n,struct node* head)
{
	int count = 0;
	struct node* counter = head;
	struct node* finder = head;
	while(count<n)
	{
		if(counter->next==NULL)
		{
			cout<<"ERROR N>LEN";
			return;
		}
		counter = counter->next;
		count++;
	}
	
	while(counter->next!=NULL)
	{
		counter = counter->next;
		finder = finder->next;
	}
	cout<<"VALUE AT "<<n<<" FROM END IS "<<finder->a<<endl;
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
	printNthFromEnd(0,head);
	printNthFromEnd(3,head);
	printNthFromEnd(5,head);
	return 0;
}