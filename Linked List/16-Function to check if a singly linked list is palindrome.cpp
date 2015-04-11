//Find if a linked list is pallindrome
#include <iostream>
using namespace std;
struct node
{
	int a;
	struct node* next;
};

void compare(struct node* first,struct node* second)
{
	while((first!=NULL)&&(second!=NULL))
	{
		if(first == NULL)
		{
			cout<<"NOT PAL";
			return;
		}
		if(second == NULL)
		{
			cout<<"NOT PALIN";
			return;
		}
		else if(first->a != second->a)
		{
			cout<<"NOT PALINDROME";
			return;
		}
		first = first->next;
		second = second->next;
	}
	cout<<"PALINDROME";
}

void reverse(struct node** headRef)
{
	struct node* cur = *headRef;
	struct node* next;
	struct node* prev = NULL;
	
	while(cur!=NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	
	*headRef = prev;
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

void isPalindrome(struct node** headRef)
{
	struct node* slow = *headRef;
	struct node* fast = *headRef;
	struct node* mid = NULL;
	struct node* secondHalfHead = NULL;
	struct node* previous;
	int a;
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast = fast->next->next;
		previous = slow;
		slow = slow->next;
	}
	
	//fast==NULL if even, otherwise store mid element and move forward
	if(fast!=NULL)
	{
		mid = slow;
		slow = slow->next;
	}
	
	secondHalfHead = slow;
	
	previous->next = NULL;
	print(slow);
/*	reverse(&secondHalfHead);
	compare(*headRef,secondHalfHead);
	reverse(&secondHalfHead);*/
	
	/*if(mid==NULL)
	{
		previous->next= secondHalfHead;
	}
	else
	{
		previous->next = mid;
		mid->next = secondHalfHead;
	}*/
}

void push(int data,struct node** headRef)
{
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->a = data;
	temp->next = *headRef;
	*headRef = temp;
	
}


int main() {
	// your code goes here
	struct node* head;
	push(1,&head);
	push(2,&head);
	push(17,&head);
	print(head);
	cout<<endl;
	isPalindrome(&head);
	//print(head);
	return 0;
}