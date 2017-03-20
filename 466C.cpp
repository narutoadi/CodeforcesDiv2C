#include<iostream>
#define N 500005
using namespace std;
int main()
{
    long long n,a[N],i,j,k,first,second;
    cin>>n;
    cin>>a[0];
    for(i=1;i<n;i++)
    {
        cin>>j; a[i]=a[i-1]+j;
    }
    if(n<3) {cout<<"0"<<endl; return 0;}
    if(a[n-1]%3 !=0) {cout<<"0"<<endl; return 0;}
    first = a[n-1]/3;
    second = first*2;
    long long ans=0, countFirsts=0;
    for(i=0;i<n-1;i++)
    {
        if(a[i]==second) ans+=countFirsts;
        if(a[i]==first) countFirsts++;
    }
    cout<<ans<<endl;
    return 0;
}
        

