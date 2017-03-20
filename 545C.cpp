#include<iostream>
#define N 100005
using namespace std;
int main()
{
    int n,x[N],h[N],i,j,k,L,R,tempL;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>x[i]>>h[i];
    
    if(n==1) {cout<<1<<endl; return 0;}
    if(n==2) {cout<<2<<endl; return 0;}

    x[n+1]=-1;
    int dp[n][2]; // second column will store if the tree will go left(0) or right(1)
    // first column will store for trees upto i how many can fall at max;
    dp[1][0]=1;
    dp[1][1]=0;
    L=x[1]+1; // left most available space for the next tree
    R=x[3]-1; // right most "           "   "       "
    for(i=2;i<n;i++)
    {
        int ht = h[i];
        // if the tree can go to left
        if(x[i]-h[i] >= L) {dp[i][0]=dp[i-1][0]+1; dp[i][1]=0; L=x[i]+1; R=x[i+2]-1;}
        // check for right
        else if(x[i]+h[i] <= R) {dp[i][0]=dp[i-1][0]+1; dp[i][1]=1; L=x[i]+h[i]+1; R=x[i+2]-1;}
        // if the previous one fell to right just uncut it and see if current one can go to left
        else if(dp[i-1][1] == 1)
        {
            tempL = L-h[i-1];
            if(x[i]-h[i] >= tempL) {dp[i][0] = dp[i-1][0]; dp[i][1]=0; dp[i-1][0]--; dp[i-1][1]=-1; L=x[i]+1; R=x[i+2]-1;}
            else
            {
                dp[i][0]=dp[i-1][0];
                dp[1][1]=-1;
                L=x[i]+1;
                R=x[i+2]-1;
            }
        }
        else
        {
            dp[i][0]=dp[i-1][0];
            dp[1][1]=-1;
            L=x[i]+1;
            R=x[i+2]-1;
        }
    }

    cout<<dp[n-1][0]+1<<endl;
    return 0;
}


