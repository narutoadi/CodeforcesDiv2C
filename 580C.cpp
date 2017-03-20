#include <iostream>
#include <queue>
#include <list>
using namespace std;
class graph{
    int V;
    bool *cat;
    list<int>*adj;
    public :
        graph(int v)
        {
            this->V = v;
            this->cat = new bool[v];
            this->adj = new list<int>[v];
        }
        void addCat(int i, bool j)
        {
            cat[i]=j;
        }
        void addEdge(int v, int w);
        int bfs(int s,int m);
};

void graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int graph::bfs(int s, int m){
    int countWays=0;
    int x;
    bool flag=0;
    bool visited[V]={0};
    list <pair<int, int> >queue;
    visited[s]=1;
    x=0;
    if(cat[s]) x=1;
    queue.push_back(make_pair(s,x));
    list<int>::iterator i;
    while(!queue.empty())
    {
        s=queue.front().first;
        x=queue.front().second;
        flag=0;
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i]=1;
                if(cat[*i]&&x<m)
                    queue.push_back(make_pair(*i, x+1));
                else if(!cat[*i]&&x<=m) queue.push_back(make_pair(*i, 0));
                flag=1;
            }
        }
        queue.pop_front();
        if(flag==0&&x<=m) countWays++;
    }
    return countWays;
}


int main()
{
    ios::sync_with_stdio(false);
    int n,m,i,j,k,a,b;
    bool x;
    cin>>n>>m;
    graph g(n);
    for(i=0;i<n;i++) 
    {
        cin>>x;
        g.addCat(i,x);
    }





    for(i=1;i<n;i++)
    {
        cin>>a>>b;
        g.addEdge(a-1,b-1);
    }
    cout<<g.bfs(0,m);
    return 0;
}


