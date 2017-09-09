#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1002;
const int M=500050;
bool vis[N];
vector<int> map[N];
struct edge
{
    int x,y;double d;
    bool operator<(edge a)const{return d<a.d;}
}e[M],res[N];
int n,cnt,set[N];
double sum;
struct point{int x,y,po;}p[N];
double dis(point a,point b){return sqrt(1.0*((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));}
int find(int x)
{
    if(set[x]!=x) set[x]=find(set[x]);
    return set[x];
}
bool Union(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx==fy) return false;
    set[fy]=fx;
    return true;
}
void krusal()
{
    int i,j=0;
	sort(e,e+cnt);
	for(i=1;i<=n;i++)set[i]=i;
    for(i=0;i<cnt;i++)
    {
        if(Union(e[i].x,e[i].y))
        {
			map[e[i].x].push_back(e[i].y);
			map[e[i].y].push_back(e[i].x);
            sum+=e[i].d;
            res[j]=e[i];
            j++;
        }
        if(j==n-1)return;
    }
}
int maxpo;
void dfs(int x)
{
    int i;vis[x]=1;
    if(p[x].po>maxpo)maxpo=p[x].po;
	for(i=0;i<map[x].size();i++)if(!vis[map[x][i]])dfs(map[x][i]);
}
void pre()
{
    int i,j; 
	scanf("%d",&n);
    for(i=1;i<=n;i++){scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].po);map[i].clear();}
    cnt=0;
    for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)
    {
        e[cnt].x=i;e[cnt].y=j;
        e[cnt].d=dis(p[i],p[j]);
        cnt++;
    }
    sum=0;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        pre();
        krusal();
        double ans=0,tmp; 
        for(i=0;i<n-1;i++)
        {
			int x=res[i].x,y=res[i].y;
            tmp=0;
            memset(vis,0,sizeof(vis));
			vis[y]=true;maxpo=0;dfs(x);
			tmp+=maxpo;
            memset(vis,0,sizeof(vis));
			vis[x]=true;maxpo=0;dfs(y);
			tmp+=maxpo;
            tmp/=(sum-res[i].d);
            if(tmp>ans)ans=tmp;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}