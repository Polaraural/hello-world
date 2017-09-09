相信大家都听说一个“百岛湖”的地方吧，
百岛湖的居民生活在不同的小岛中，
当他们想去其他的小岛时都要通过划小船来实现。
现在政府决定大力发展百岛湖，发
展首先要解决的问题当然是交通问题，
政府决定实现百岛湖的全畅通！
经过考察小组RPRush对百岛湖的情况充分了解后，
决定在符合条件的小岛间建上桥，所谓符合条件，
就是2个小岛之间的距离不能小于10米，也不能大于1000米。
当然，为了节省资金，
只要求实现任意2个小岛之间有路通即可。其中桥的价格为 100元/米。 
Input
输入包括多组数据。
输入首先包括一个整数T(T <= 200)，
代表有T组数据。 
每组数据首先是一个整数C(C <= 100),
代表小岛的个数，接下来是C组坐标，
代表每个小岛的坐标，这些坐标都是 0 <= x, y <= 1000的整数。 
Output
每组输入数据输出一行，
代表建桥的最小花费，结果保留一位小数。
如果无法实现工程以达到全部畅通，输出”oh!”.
Sample Input
2
2
10 10
20 20
3
1 1
2 2
1000 1000
Sample Output
1414.2
oh!


#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100+10;
const int INF = 1000000;
struct Node
{ 
   int x;
   int y;
   int distance;	
}node[maxn];
double dis[maxn];
double map[maxn][maxn];
int vis[maxn];
int val[maxn];
int n,m;
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
                vis[cur]=1;  
    }  
      
}  

double get_distance(int x1,int y1,int x2,int y2){
	int distance_;
	int c1 = (x1-x2)*(x1-x2);
	int c2 = (y1-y2)*(y1-y2);
	distance_ = sqrt(c1+c2);
	return distance_;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				map[i][j] = INF;
		
		for(int i=1;i<=n;i++){
			scanf("%d%d",&node[i].x,&node[i].y);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){  // 优化
				if(map[i][j]>get_distance(node[i].x,node[i].y,node[j].x,node[j].y))
				map[i][j] =map[j][i] =  get_distance(node[i].x,node[i].y,node[j].x,node[j].y); 
			}
		}
		dijkstra(1);
		printf("%.1lf\n",dis[n]*100);

	}
	return 0;
}