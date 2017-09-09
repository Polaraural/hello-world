Invitation Cards
Time Limit: 8000MS		Memory Limit: 262144K
Total Submissions: 27806		Accepted: 9275
Description
//题目大意：志愿者从起点出发，遍历所有点之后回到起点，求最少的花费。是有向图

//测试样例
2
   
4 6
1 2 10
2 1 60
1 3 20
3 4 10
2 4 5
4 1 50
Sample Output

46
210

//准备用Bellman-Ford算法写一下
//对于回路的问题，在《浅析差分约束系统》里面看到了一个很巧妙的方法：
                                                               //就是先按照给定的方向求起点到终点的距离
                                                               //然将所有的方向调反再求一遍起点到终点的距离加起来就是最短的距离
//QAQ 现在去吃饭 吃完饭回来写这个代码 去吃饭的路上在脑子里面构思代码
//吃饭回来了 现在开始写题

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 10000+10;
const int INF = 1000005;
int n,m;
bool vis[maxn];
int map[maxn][maxn];
int dis[maxn];
void Bellman_Ford(int s)
{
	//memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i] = INF;

	bool vis[maxn] = {0};
	dis[s] = 0;
    vis[s] = true;
	queue<int> q;
	q.push(s);
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		vis[cur] = false;
		for(int i=1;i<=n;i++){
			if(dis[i]>dis[cur]+map[cur][i])
				{
					dis[i] = dis[cur] + map[cur][i];
			if(!vis[i]){
				vis[i] = true;
				q.push(i);
			}
				}
		}
	}
}

int main(int argc, char const *argv[])
{
	int from[maxn],to[maxn],val[maxn];
	int T;
	scanf("%d",&T);
	while(T--){
		int sum1 = 0;
		int sum2 = 0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				map[i][j] = INF;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&from[i],&to[i],&val[i]);
			if(map[from[i]][to[i]]>val[i])
				map[from[i]][to[i]] = val[i];
		}
		Bellman_Ford(1);
		if(dis[n]==INF) printf("-1\n");
		else sum1 = dis[n];
		//memset(map,0,sizeof(map));
		for(int i=1;i<=n;i++)
			for(int j=0;j<n;j++)
				map[i][j] = 0;
		for(int i=1;i<=m;i++){
			if(map[from[i]][to[i]]>val[i])
			map[to[i]][from[i]] = val[i];	
		}
        Bellman_Ford(1);
        if(dis[n]==INF) printf("-1\n");
		else sum2 = dis[n];

		printf("%d\n",sum1+sum2);

	}
	return 0;
}



//
#include <cstdio>  
#include <queue>  
using namespace std;  
const int INF=1000000;  
const int MAXN=200+10;  
int n,m;  
int map[MAXN][MAXN];  
int dis[MAXN];  
void SPFA(int s)  
{  
    for(int i=0;i<n;i++)  
        dis[i]=INF;  
  
    bool vis[MAXN]={0};  
      
    vis[s]=true;  
    dis[s]=0;  
      
    queue<int> q;  
    q.push(s);  
    while(!q.empty())  
    {  
        int cur=q.front();  
        q.pop();  
        vis[cur]=false;  
        for(int i=0;i<n;i++)  
        {  
            if(dis[cur] + map[cur][i] < dis[i])  
            {  
                dis[i]=dis[cur] + map[cur][i];  
                if(!vis[i])  
                {  
                    q.push(i);  
                    vis[i]=true;  
                }  
            }             
        }  
    }  
}  
int main()  
{   
	int T;
	scanf("%d",&T);
	while(T--)
    {
    	scanf("%d%d",&n,&m)
    {  
        for(int i=0;i<n;i++)  
            for(int j=0;j<n;j++)  
                map[i][j]=INF;  
  
        for(int i=0;i<m;i++)  
        {  
            int from,to,dis;  
            scanf("%d%d%d",&from,&to,&dis);  
            if(map[from][to]>dis)  
                map[from][to]=dis;  
        }  
        //int s,t;  
        //scanf("%d%d",&s,&t);  
        SPFA(1);  
        if(dis[n]==INF)  
            puts("-1");  
        else  
            printf("%d\n",dis[n]);  
      }  
    }
    return 0;  
}  


//
#include <cstdio>  
#include <cstring>  
const int MAXN=200+10;  
const int INF=1000000;  
int n,m,map[MAXN][MAXN],dis[MAXN];  
bool vis[MAXN];  
  
void dijkstra(int s)  
{  
    memset(vis,0,sizeof(vis));  
    int cur=s;  
    dis[cur]=0;  
    vis[cur]=1;  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=1;j<=n;j++)  
            if(!vis[j] && dis[cur] + map[cur][j] < dis[j])  
                dis[j]=dis[cur] + map[cur][j] ;  
  
        int mini=INF;  
        for(int j=1;j<=n;j++)  
            if(!vis[j] && dis[j] < mini)  
                mini=dis[cur=j];  
        vis[cur]=true;  
    }  
      
}  
int main()  
{  
    while(~scanf("%d%d",&n,&m))  
    {  
        for(int i=1;i<=n;i++)  
        {  
            dis[i]=INF;  
            for(int j=1;j<=n;j++)  
                map[i][j]=INF;  
        }  
        for(int i=1;i<=m;i++)  
        {  
            int from,to,val;  
            scanf("%d%d%d",&from,&to,&val);  
            if(map[from][to] > val)  
                map[to][from]=map[from][to]=val;          
        }  
        //int s,t;  
        //scanf("%d%d",&s,&t);  
        dijkstra(1);  
        if(dis[n]==INF)  
            printf("-1\n");  
        else  
            printf("%d\n",dis[n]);  
    }  
    return 0;  
  
}  


//
#include <cstdio>  
#include <algorithm>  
using namespace std;  
const int MAXN=1010;  
const int INF=99999;  
int map[MAXN][MAXN];  
int n,m,x;  
void map_reverse()  
{  
    for(int i=1;i<=n;i++)  
        for(int j=1;j<i;j++)  
            swap(map[i][j],map[j][i]);  
}  
  
void dijkstra(int s)  
{  
    bool vis[MAXN]={0};  
    int cur=s;  
    vis[cur]=true;  
    dis[cur]=0;  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=1;j<=n;j++)  
            if(map[cur][j]!=INF && map[cur][j] +dis[cur] < dis[j])  
                dis[j]=map[cur][j] +dis[cur];  
  
        int mini=INF;  
        for(int j=1;j<=n;j++)  
            if(!vis[j] && dis[j] < mini)  
                mini=dis[cur=j];  
  
        vis[cur]=true;  
    }  
  
}  
int main()  
{  
  
    while(~scanf("%d%d",&n,&m))  
    {  
        for(int i=1;i<=n;i++)  
        {  
            for(int j=1;j<=n;j++)  
                map[i][j]=INF;  
        }  
  
        for(int i=0;i<m;i++)  
        {  
            int a,b,t;  
            scanf("%d%d%d",&a,&b,&t);  
            map[a][b]=t;  
        }  
  
        int dis1[MAXN],dis2[MAXN];  
        for(int i=1;i<=n;i++)  
            dis1[i]=dis2[i]=INF;  
  
        dijkstra(dis1);  
        map_reverse();  
        dijkstra(dis2);  
  
        int ans=-1;  
        for(int i=1;i<=n;i++)  
        {  
            if(dis1[i]==INF || dis2[i]==INF)  
                continue;  
  
            int temp=dis1[i]+dis2[i];  
            if(temp > ans)  
                ans=temp;  
        }  
  
        printf("%d\n",ans);  
    }  
  
    return 0;  
}  