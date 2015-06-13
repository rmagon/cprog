#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> st;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if((s[i]=='(')||(s[i]=='[')||(s[i]=='{'))
		st.push(s[i]);
		else if(s[i]==')')
		{
			if(st.top()=='(')
			{
				st.pop();
			}
			else
			{
				cout<<"invalid";
				return 0 ;
			}
		}
		else if(s[i]==']')
		{
			if(st.top()=='[')
			{
				st.pop();
			}
			else
			{
				cout<<"invalid";
				return 0;
			}
		}
		else if(s[i]=='}')
		{
			if(st.top()=='{')
			{
				st.pop();
			}
			else
			{
				cout<<"invalid";
				return 0;
			}
		}
		else
		{}
	}

	cout<<"Valid";
	return 0;
}