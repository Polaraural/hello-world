#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 600;
const int INF  = 10000000;
int n,m;
//int cost[maxn];
int dis[maxn];
int vis[maxn];
int map[maxn][maxn];
int score[maxn];
int point[maxn];
void dijkstra(int s){
    int cur = s;
    for(int i=0;i<n;i++){
        vis[i] = 0;
        dis[i] = INF;
        score[i] = 0;
    }
    dis[cur] = 0;
    score[cur] = point[cur];
    for(int i=0;i<n;i++){
        int mini  = INF;
        cur = -1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&dis[j]<mini){
                mini = dis[cur = j];
            }
        }
        if(cur==-1) break;
        vis[cur] = 1;
        for(int j=0;j<n;j++){
            if(!vis[j] && dis[j]>dis[cur]+map[cur][j]||(dis[j] == dis[cur] + map[cur][j] && score[j] < score[cur] + point[j])){
                dis[j] = dis[cur] + map[cur][j];
                score[j] = score[cur] + point[j];
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int s,e;
    int from,to,val;
    //freopen("input.txt","r",stdin);
   //freopen("optput.txt","w",stdout);
    while(~scanf("%d %d %d %d",&n,&m,&s,&e)){
        for(int i=0;i<n;i++) 
        scanf("%d",&point[i]);
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++){
                    map[i][j] = INF;
                }
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&from,&to,&val);
            if(map[from][to] > val){
            //if(map[from][to]>val){
                map[from][to] = map[to][from] = val;
            }
        }
        dijkstra(s);
        printf("%d %d\n",dis[e],score[e]);
    }
    return 0;
}