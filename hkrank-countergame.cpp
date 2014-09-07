#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        unsigned long long int n;
        cin>>n;
        bool rWin = true;
        while(n>1)
        {
            rWin = !rWin;
            double ans = log2(n);
            if(floor(ans)==ans){
                n = n/2;
            }
            else{
                n-= (unsigned long long)pow(2,(unsigned long long)(log2(n)));
            }
        }
        if(rWin)
        {
            cout<<"Richard"<<endl;
        }
        else
        {
            cout<<"Louise"<<endl;
        }
    }
    return 0;    
}