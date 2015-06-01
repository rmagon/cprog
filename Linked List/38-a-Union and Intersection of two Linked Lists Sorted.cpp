#include <iostream>
using namespace std;

struct node
{
	int a;
	struct node* next;
};

void insert(struct node** head,int data)
{
	struct node* looper = *head;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->a = data;
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
		printf("%d ",head->a);
		head = head->next;
	}
	printf("\n");
}

void splitIntoTwo(struct node* head, struct node** a,struct node** b)
{
	struct node* slow = head;
	struct node* fast = head->next;
	
	while((fast!=NULL)&&(fast->next!=NULL))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

struct node* merge(struct node* list1,struct node* list2)
{
	struct node* head;
	
	if(list1==NULL)
	return list2;
	if(list2==NULL)
	return list1;
	
	if(list1->a < list2->a)
	{
		head = list1;
		list1 = list1->next;
	}
	else
	{
		head = list2;
		list2 = list2->next;
	}
	head->next=merge(list1,list2);
	return head;
}

void mergeSort(struct node** headRef)
{
	struct node* head = *headRef;
	struct node* a;
	struct node* b;
	
	if((head==NULL)||(head->next==NULL))
	{
		return;
	}

	splitIntoTwo(head,&a,&b);

	mergeSort(&a);
	mergeSort(&b);
	
	*headRef = merge(a,b);
}

struct node* sortedIntersection(struct node* list1, struct node* list2)
{
	struct node* sUHead = NULL;
	
	while((list1!=NULL)&&(list2!=NULL))
	{
		if(list1->a == list2->a)
		{
		insert(&sUHead,list1->a);
		list1 = list1->next;
		list2 = list2->next;
		}
		else if(list1->a < list2->a)
		{
			list1 = list1->next;
		}
		else
		{
			list2 = list2->next;
		}
	}
	return sUHead;
}

struct node* sortedUnion(struct node* list1,struct node* list2)
{
	struct node* sUHead;
	
	if(list1->a == list2->a)
	{
		sUHead = list1;
		list1 = list1->next;
		list2 = list2->next;
	}
	else if(list1->a < list2->a)
	{
		sUHead = list1;
		list1 = list1->next;
	}
	else
	{
		sUHead = list2;
		list2 = list2->next;
	}
	
	if(list1==NULL)
	{
		sUHead->next = list2;
	}
	else if(list2 == NULL)
	{
		sUHead->next = list1;
	}
	else
	{
	sUHead->next = sortedUnion(list1,list2);
	}
	
	return sUHead;
	
	
}
int main() {
	struct node* head = NULL;
	struct node* head2 = NULL;
	
	insert(&head,155);
	insert(&head,2);
	insert(&head,30);
	insert(&head,150);
	
	insert(&head2,150);
	insert(&head2,2);
	insert(&head2,50);
	
	mergeSort(&head);
	mergeSort(&head2);
	print(head);
	print(head2);
		
	cout<<"INTERSECTION ";
	struct node* sortedInter = sortedIntersection(head,head2);
	print(sortedInter);
	
	cout<<"UNION ";
	struct node* sortedUnionHead = sortedUnion(head,head2);
	print(sortedUnionHead);

	
//	print(merge(head,head2));
	return 0;
}