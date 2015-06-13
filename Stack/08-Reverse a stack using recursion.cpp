#include <iostream>
#include <string>
#include <stack>
using namespace std;

void reverse(stack<int>* st)
{
	if((*st).empty()==false)
	{
	int i = (*st).top();
	(*st).pop();
	reverse(st);
	stack<int> temp;
	while((*st).empty()==false)
	{
		temp.push((*st).top());
		(*st).pop();
	}
	(*st).push(i);
	while(temp.empty()==false)
	{
		(*st).push(temp.top());
		temp.pop();
	}
	}
}
int main() {
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout<<"REVERSE"<<endl;
	reverse(&st);
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	return 0;
}