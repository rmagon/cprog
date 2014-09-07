#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
    cin>>n;
    int a[102][102];
    int b[102][102];
    string row;
    for(int i=0;i<n;i++)
    {
        cin>>row;
        for(int j=0;j<n;j++)
        {
            a[i][j] = row[j] - 48;
            b[i][j] = a[i][j];
        }       
    }
    
for( int i = 1; i < n-1; ++i ) {
		for( int j = 1; j < n-1; ++j ) {
			if( a[i][j] <= a[i][j-1] ) continue;
			if( a[i][j] <= a[i-1][j] ) continue;
			if( a[i][j] <= a[i+1][j] ) continue;
			if( a[i][j] <= a[i][j+1] ) continue;
			b[i][j] = -1;
		}
	}
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]!=-1)
            cout<<b[i][j];
            else
            cout<<"X";
        } 
        cout<<"\n";
    }
	return 0;
}