
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1010,M=500010;
int p[N];
int n,m,k;
struct edge
{
    int a,b;
}e[M];
int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m>>k;

    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&e[i].a,&e[i].b);
    }
    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        int cnt=n-1;
        for(int i=1;i<=n;i++) p[i]=i;
        for(int i=0;i<m;i++)
        {
            int a=e[i].a,b=e[i].b;
            if(a!=x&&b!=x)
            {
                int pa=find(a),pb=find(b);
                if(pa!=pb)
                {
                    p[pa]=pb;
                    cnt--;
                }
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}
