#include <iostream>
#include <stack>
using namespace std;

struct Stack 
{
	int top=-1;
	stack<int> st;
	stack<int> minS;
};

void push(Stack* s,int k)
{
	s->st.push(k);
	if((s->minS.empty())||(k<s->minS.top()))
	{
		s->minS.push(k);
	}
	else
	{
		s->minS.push(s->minS.top());
	}
}

int pop(Stack* s)
{
	int t=s->st.top();
	s->st.pop();
	s->minS.pop();
	return t;
}

int minVal(Stack *s)
{
	return s->minS.top();
}
int main() {
	
	struct Stack s;
	push(&s,5);
	push(&s,6);
	push(&s,7);
	push(&s,3);
	push(&s,9);
	push(&s,1);
	while(!s.minS.empty())
	{
		cout<<s.minS.top()<<" ";
		s.minS.pop();
	}
	return 0;
}