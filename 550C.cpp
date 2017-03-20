#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int i,j,k,l,len1,len2;
    char s[102];
    bool finalflag=0;
    cin>>s;
    l=strlen(s)-1;
    for(i=0;i<=l;i++)
    {
        if(s[i]=='0') {cout<<"YES\n0"<<endl; return 0;}
        if(s[i]=='8') {cout<<"YES\n8"<<endl; return 0;}
    }
    for(i=0;i<126;i++)
    {
//        cout<<i<<" ";
        j=8*i;
        l=strlen(s)-1;
  //      cout<<j<<" "<<l<<endl;
        len1 = log10(j)+1;len2=0;
        while(j)
        {
            k=j%10;
            j=j/10;
            bool flag=0;

            for(;l>=0;l--)
            {
                if(s[l]-'0' == k){flag=1;len2++;l--;break;}
            }
            if(flag==0) j=0;
            else if(len2==len1) {finalflag=1; break;}
        }
    //    cout<<len1<<" "<<len2<<endl;
        if(finalflag==1) {cout<<"YES"<<endl; cout<<8*i<<endl; return 0;}
    }
    cout<<"NO"<<endl;
    return 0;
}
