#include <iostream>
using namespace std;

struct Stack
{
	int top;
	int capacity;
	int* array;
};

struct Stack createStack(int size)
{
	struct Stack stack;
	stack.top = -1;
	stack.capacity = size;
	stack.array = (int*)malloc(sizeof(int)*size);
	return stack;
}

int pop(struct Stack* stack)
{
	if(stack->top==-1)
	{
	return -999;
	}
	else
	{
		stack->top--;
		return stack->array[stack->top+1];
	}
}

void push(struct Stack* stack, int k)
{
	if(stack->top == (stack->capacity-1))
	cout<<"Overflow";
	else
	{
		stack->top++;
		stack->array[stack->top] = k;
	}
}
int main() {
	// your code goes here
	struct Stack s = createStack(3);
	push(&s,1);
	push(&s,2);
	push(&s,4);
	cout<<"pop ="<<pop(&s)<<endl;
	cout<<"pop ="<<pop(&s)<<endl;
	cout<<"pop ="<<pop(&s)<<endl;
	cout<<"pop ="<<pop(&s)<<endl;
	return 0;
}