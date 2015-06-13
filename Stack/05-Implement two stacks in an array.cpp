#include <iostream>
using namespace std;

struct Stack{
int n[10];
int top1=-1,top2=10;
};

int pop(int whichStack,struct Stack* s)
{
	if(whichStack == 1)
	{
		if(s->top1 > -1)
		{
			s->top1--;
			return s->n[s->top1+1];
		}
		else
		{
			cout<<" 1-underflow ";
			return -1;
		}
	}
	else
	{
		if(s->top2 < 10)
		{
			s->top2++;
			return s->n[s->top2-1];
		}
				else
		{
			cout<<" 2-underflow ";
			return -1;
		}
	}
}

void push(int whichStack,struct Stack* s,int k)
{
	if(whichStack == 1)
	{
		if(s->top1<(s->top2-1))
		{
			s->n[s->top1+1] = k;
			s->top1++;
		}
		else
		{
			cout<<"Stack 1 Overflow "<<endl;
		}
	}
	else
	{
		if(s->top2>(s->top1+1))
		{
			s->n[s->top2-1] = k;
			s->top2--;
		}
		else
		{
			cout<<"Stack 2 Overflow"<<endl;
		}
	}
}

int main() {
	struct Stack s1;
	push(1,&s1,12);
	push(1,&s1,11);
	push(1,&s1,10);
	push(1,&s1,9);
	push(1,&s1,8);
	push(1,&s1,7);
	push(1,&s1,6);
	push(1,&s1,5);
	push(2,&s1,500);
	push(2,&s1,501);
	push(2,&s1,502);
	cout<<pop(1,&s1)<<" "<<pop(2,&s1)<<" "<<pop(2,&s1)<<" "<<pop(2,&s1);
	return 0;
}