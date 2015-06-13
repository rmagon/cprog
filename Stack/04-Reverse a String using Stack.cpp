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
		st.push(s[i]);
	}
	for(int i=0;i<s.length();i++)
	{
		s[i] = st.top();
		st.pop();
	}
	cout<<s;
	return 0;
}