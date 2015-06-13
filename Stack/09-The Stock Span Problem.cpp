#include <iostream>
#include <stack>
#define SIZE 6
using namespace std;

int main() {
	stack<int> st;
	//int arr[SIZE];
	int span[SIZE];
	/*arr[0] = 100;
	arr[1] = 80;
	arr[2] = 60;
	arr[3] = 70;
	arr[4] = 60;
	arr[5] = 75;
	arr[6] = 85;*/
	int arr[] = {10, 4, 5, 90, 120, 80};
	st.push(0);
	span[0] = 1;
	for(int i=1;i<SIZE;i++)
	{
		//int spanCount = 1;
		while(arr[st.top()] <= arr[i])
		{
			st.pop();
			if(st.empty())
			break;
			
		}
		if(!st.empty())
		{
			span[i] = i - st.top();
		}
		else
		{
			span[i] = i+1;
		}
		st.push(i);
	}
	while(!st.empty())
	{
		span[st.top()] == 1;
		st.pop();
	}
	for(int i=0;i<SIZE;i++)
	{
		cout<<span[i]<<" ";
	}
	cout<<endl;
	return 0;
}