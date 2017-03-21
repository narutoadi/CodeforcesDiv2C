#include<iostream>
#include<algorithm>
#define N 300005
using namespace std;
int main()
{
    int n,i,j,k,a[N];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long ans=0;
    for(i=0;i<n;i++)
    {
        j=i+1-a[i];
        if(j<0) j = -1*j;
        ans= ans+j;
    }
    cout<<ans<<endl;
    return 0;
}

