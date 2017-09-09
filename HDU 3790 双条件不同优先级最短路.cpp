/*

HDU 3790

给你n个点，m条无向边，每条边都有长度d和花费p，给你起点s终点t，
要求输出起点到终点的最短距离及其花费，
如果最短距离有多条路线，则输出花费最少的。 
Input
输入n,m，点的编号是1~n,然后是m行，
每行4个数 a,b,d,p，表示a和b之间有一条边，
且其长度为d，花费为p。
最后一行是两个数 s,t;起点s，
终点。n和m为0时输入结束。 
(1<n<=1000, 0<m<100000, s!= t)
Output
输出 一行有两个数， 最短距离及其花费。
Sample Input
3 2
1 2 5 6
2 3 4 5
1 3
0 0
Sample Output
9 11

*/
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn  = 1100;
const int INF = 1000000;
int n,m;
int cost[maxn],dis[maxn];
int vis[maxn];
int map[maxn][maxn];
int money[maxn][maxn];
void dijkstra(int s){
  int cur = s;
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++){
     dis[i] = INF;
     cost[i] = INF;
  }
    dis[cur] = 0;
    cost[cur] = 0;
    //vis[cur] = 1;
    for(int i=1;i<=n;i++){
    	int mini = INF;
    		cur = -1;
    		for(int j=1;j<=n;j++){
    			if(!vis[j]&&dis[j]<mini){
    				mini = dis[cur=j];
    				
    			}
    		}
    		if(cur==-1) 
    		break;
    	    vis[cur] = 1;
    	for(int j=1;j<=n;j++){
    		if(dis[j]>dis[cur]+map[cur][j]||(dis[j]==dis[cur]+map[cur][j]&&cost[j]>cost[cur]+money[cur][j])){  //双松弛操作
    			dis[j]=dis[cur]+map[cur][j];
    			cost[j]=cost[cur]+money[cur][j]; 
    		}
    	}
    		
    		
    }
}
int main(int argc, char const *argv[])
{
	int s,e;
	int from,to,val,money_node;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
	  for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++){
    		map[i][j] = INF;
    		money[i][j] = INF;
    	}
        for(int i=0;i<m;i++){
    	   scanf("%d%d%d%d",&from,&to,&val,&money_node);
    	      if(map[from][to]>val||(map[from][to]==val&&money[from][to]>money_node)){
    		       map[from][to] =map[to][from] =  val;
    	           money[from][to] = money[to][from] = money_node;}
    	}    
        scanf("%d%d",&s,&e);
        dijkstra(s);
        printf("%d %d\n",dis[e],cost[e]);
	}
  

}
