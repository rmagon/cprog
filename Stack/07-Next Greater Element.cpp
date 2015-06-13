#include <iostream>
#include <stack>
#define SIZE 4
using namespace std;

int main() {
	stack<int> st;
	
	int arr[4];
	arr[0] = 11;
	arr[1] = 13;
	arr[2] = 21;
	arr[3] = 3;
	st.push(arr[0]);
	for(int i=1;i<4;i++)
	{
		int next = arr[i];
		int element = st.top();
		while(element < next)
		{
			st.pop();
			cout<<"Next of "<<element<<" -> "<<next<<endl;
			if(st.empty())
			{
				break;
			}
			element = st.top();
		}
		st.push(next);
	}
	while(!st.empty())
	{
		cout<<"Next of "<<st.top()<<" -> -1"<<endl;
		st.pop();
	}
	return 0;
}