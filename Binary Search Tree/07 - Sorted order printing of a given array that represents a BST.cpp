#include <iostream>
using namespace std;

void printInOrder(int a[],int root)
{
	if(root>4)
	return;
	
	printInOrder(a,2*root+1);
	cout<<a[root];
	printInOrder(a,2*root+2);
}

int main() {
	int a[] = {4, 2, 5, 1, 3};
	printInOrder(a,0);
	return 0;
}