/* 
A Recursive program to print all permutations of a string
Input: Any string
Output: All permutations of the string
Source: http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/
#include <iostream>
#include <string>
using namespace std;

void permute(int b,string a)
{
	if(b==a.length())
	{
		cout<<a<<endl;
	}
	else
	{
		for(int i=b;i<a.length();i++)
		{
			char temp = a[b];
			a[b] = a[i];
			a[i] = temp;
			permute(b+1,a);
			temp = a[i];
			a[i] = a[b];
			a[b] = temp;
		}
	}
}
int main() {
	permute(0,"ABCD");
	return 0;
}