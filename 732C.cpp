#include<iostream>
using namespace std;
int main()
{
    long long b,l,d,max,ans;
    cin>>b>>l>>d;
    if(b>l && b>d) 
    {
        max=b-1;
        ans = 2*max-l-d;
    }
    else if(l>b && l>d)
    {
        max=l-1;
        ans = 2*max-b-d;
    }
    else if(d>b && d>l)
    {
        max=d-1;
        ans = 2*max-b-l;
    }
    else if(b==l && l==d)
    {
        ans=0;
    }
    else if(b==l){
        ans=b-1-d;
    }
    else if(l==d){
        ans=l-1-b;
    }
    else if(b==d){
        ans=b-l-1;
    }
    cout<<ans<<endl;
    return 0;
}
