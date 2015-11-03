#include <iostream>
#include <queue>
using namespace std;

void createBin(int n)
{
	queue<string> q;
	
	q.push("1");
	
	while(n--)
	{
		string no = q.front();
		q.pop();
		cout<<no<<endl;
		string no0 = no.append("0");
		string no1 = no.append("1");
		q.push(no0);
		q.push(no1);
	}
}

int main() {
	int n;
	cin>>n;
	createBin(n);
	return 0;
}