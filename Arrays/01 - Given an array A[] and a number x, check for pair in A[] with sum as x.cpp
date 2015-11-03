#include <iostream>
#include <map>
using namespace std;

void printPairs(int A[], int n, int x)
{
	map<int,int> hashMap;
	for(int i=0;i<n;i++)
	{
		//cout<<"Will look for "<<x - A[i]<<"at "<<A[i];
		if(hashMap.find(x-A[i])!=hashMap.end())
		{
			cout<<"Found A Pair "<<A[i]<<","<<x-A[i]<<endl;
		}
		hashMap[A[i]]=1;
	}
	cout<<"End";
}
int main() {
	// your code goes here
	int A[] = {1, 4, 45, 6, 10, 8, 12};
    int n = 16;
    int arr_size = 7;
    printPairs(A, arr_size, n);
	getchar();
	return 0;
}