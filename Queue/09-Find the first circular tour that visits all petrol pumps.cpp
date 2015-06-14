#include <iostream>
using namespace std;

struct pump
{
    int fuel;
    int distance;
    
};

int roundTrip(pump a[], int n)
{
    int front = 0;
    int rear = 1;
    int currPetrol = a[0].fuel - a[0].distance;
  //  cout<<"Initial Petrol "<<currPetrol<<endl;
    while(front!=rear || currPetrol < 0)
    {
        while(currPetrol<0 && front!=rear)
        {
           // cout<<"Removing"<<front<<endl;
            currPetrol = currPetrol + a[front].distance - a[front].fuel;
            front = (front+1)%n;
            if(front==0)
            return -1;
        }
       // cout<<"Adding "<<rear<<" Petrol "<<currPetrol<<endl;
        currPetrol = currPetrol + a[rear].fuel - a[rear].distance;
      //  cout<<"Adding "<<rear<<" Petrol "<<currPetrol<<endl;
        rear = (rear + 1)%n;
    }
    return front;
    
}
int main() {
	 struct pump arr[] = {{6, 4}, {3, 6}, {7, 3}};
	 int n = sizeof(arr)/sizeof(arr[0]);
	  int start = roundTrip(arr, n);
 
    (start == -1)? printf("No solution"): printf("Start = %d", start);
 
	return 0;
}
