#include <iostream>
using namespace std;

struct node
{
	int x;
	int y;
	struct node* next;
};

void insert(struct node** head,int x,int y)
{
	struct node* looper = *head;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	if((*head) == NULL)
	{
		(*head) = temp;
		return;
	}
	else
	{
		while(looper->next!=NULL)
		{
			looper = looper->next;
		}
		looper->next = temp;
		return;
	}
}

void print(struct node* head)
{
	while(head!=NULL)
	{
		printf("(%d,%d) ",head->x,head->y);
		head = head->next;
	}
	printf("\n");
}
struct node* removeMiddlePoints(struct node* curr)
{
	struct node* preserve = curr;
	int x=curr->x,y=curr->y;
	curr=curr->next;
	while(curr->next!=NULL)
	{
		if((curr->x == x)&&(curr->next->x == x))
		{
			struct node* temp = curr;
			curr = curr->next;
			free(temp);
		}
		else if((curr->y == y)&&(curr->next->y == y))
		{
			struct node* temp = curr;
			curr = curr->next;
			free(temp);
		}
		else
		{
			preserve->next = curr;
			preserve = curr;
			x = preserve->x;
			y = preserve->y;
			curr = curr->next;
		}
		
	}
	preserve->next = curr;
}

int main() {
	struct node* head = NULL;
	
	 insert(&head, 40,5);
    insert(&head, 20,5);
    insert(&head, 10,5);
    insert(&head, 10,8);
    insert(&head, 10,10);
    insert(&head, 3,10);
    insert(&head, 1,10);
    insert(&head, 0,10);
    print(head);
	removeMiddlePoints(head);
	print(head);
	
	return 0;
}