#include<iostream>
#include<vector>
#include<algorithm>
#define N 100005
using namespace std;
int main()
{
    long long n,m,i,j,k,a[N];
    vector<int>v;
    cin>>n>>m;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    j=1;
    long long sum=0,count=0;
    bool flag=0;
    for(i=0;i<n;i++)
    {
        for(;j<a[i];j++)
        {
            if(sum+j <= m) { sum=sum+j; count++; v.push_back(j); }
            else {flag =1; break;}
        }
        if(flag==1) break;
        j=a[i]+1;
    }
    if(flag==0)
    {
        for(;j<=1000000000;j++)
        {   
            if(sum+j <= m) {sum=sum+j; count++; v.push_back(j); }
            else {flag=1; break;}
        }
    }
    if(flag==1)
    {
        cout<<count<<endl;
        vector<int>::iterator it;
        for(it=v.begin();it!=v.end();it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    return 0;
}

