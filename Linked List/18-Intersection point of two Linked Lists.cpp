#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

int lenFind(struct node* head)
{
	int count = 0;
	struct node* temp = head;
	while(temp != NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void findIntersection(struct node* head1, struct node* head2)
{
	struct node* temp1 = head1;
	struct node* temp2 = head2;
	int len1 = lenFind(head1);
	int len2 = lenFind(head2);
	//cout<<len1<<" "<<len2<<endl;
	int fix = len1 - len2;
	//cout<<"FIX ="<<fix<<endl;
	if(fix > 0)
	{
		while(fix!=0)
		{
			temp1 = temp1->next;
			fix--;
		}
	}
	else if (fix < 0)
	{
		while(fix!=0)
		{
			temp2 = temp2->next;
			fix++;
		}
	}
	while(temp1!=NULL)
	{
		//cout<<temp1<<":"<<temp1->data<<" "<<temp2<<":"<<temp2->data<<endl;
		if(temp1 == temp2)
		{
			cout<<"INTERSECTION AT "<<temp1->data;
			return;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	cout<<"NO INTERSECTION";
	
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
	struct node* head2 = NULL;
	
	insert(2,&head2);
	insert(2,&head2);
	insert(2,&head2);
	
	insert(5,&head);
	insert(6,&head);
	insert(4,&head);
	insert(3,&head);
	
	head2->next->next->next = head->next->next;
	print(head);
	print(head2);
	findIntersection(head,head2);
	return 0;
}