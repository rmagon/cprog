#include <iostream>
#include <cmath>

using namespace std;

int createSegmentTreeRecur(int arr[], int start, int end, int segT[], int index)
{
	if(start == end)
	{
		segT[index] = arr[start];
		return segT[index];
	}
	
	int mid = floor((start+end)/2);
	cout<<" start="<<start<<" mid="<<mid<<" end="<<end<<endl;
	segT[index]= createSegmentTreeRecur(arr,start,mid,segT,2*index+1) + createSegmentTreeRecur(arr,mid+1,end,segT,2*index+2);
	
	return segT[index];
}

int* createSegmentTree(int arr[],int n)
{
	int hieghtOfTree = (int)ceil(log2(n));
	int maxNodes = 2*pow(2,hieghtOfTree)-1;
	int* segTree = new int[maxNodes];

	createSegmentTreeRecur(arr,0,n-1,segTree,0);
	
	return segTree;
}

int main() {
	int arr[] = {1, 3, 5, 7, 9, 11,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int *segTree = createSegmentTree(arr,n);

	for(int i=0;i<15;i++)
	{
		cout<<segTree[i]<<" ";
	}
	return 0;
}