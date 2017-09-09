//Minimal Ratio Tree
//思路：我觉得这个题目可以用 Kruskal来写，按照最小生成树的思路。判断的时候找尽量小的边权值 和 尽量大的结点边权值
//补充：因为m是给定的 然后枚举的时候每一次的分母我们就知道了 然后只要按照最小生成树来找最小的边权就可以看
//然后就是DFS 枚举m个点 然后按照这m个点求最小生成树
#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
const int INF = 1<<30;
const double eps = 1e-5;
int lowcost[maxn];
int mp[maxn][maxn];
int w[maxn][maxn];
int node[maxn];
int ch[maxn];
bool vis[maxn];
int n,m;
int prim(int v0){
    int i,j;
    int minione;
    int minicost;
    memset(vis,0,sizeof(vis));
    int sum = 0;
    for(i=1;i<=m;i++)
        lowcost[i] = mp[v0][i];
    lowcost[v0] = 0;
    vis[v0] = 1;
    for(i=1;i<=m-1;i++){
         minicost = INF;
        for(j=1;j<=m;j++){
            if(!vis[j] && minicost > lowcost[j]){
                minicost = lowcost[j];
                 minione = j;
            }
        }
        vis[minione] = 1;
        sum+=minicost;
        for(j=1;j<=m;j++){
            if(!vis[j] && mp[minione][j] < lowcost[j]){
                lowcost[j] = mp[minione][j];
            }
        }
    }
    return sum;
}
double minians;
int ans[maxn];
void dfs(int k,int num){
    if(num==m){
        double tot = 0;
        for(int i=1;i<=m;i++)
             tot+=(double)node[ch[i]];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++)
                mp[i][j] = w[ch[i]][ch[j]];
        }
        double sum = prim(1)*1.0;
        double temp = sum/tot;
        if(minians-temp>=eps){
            minians = temp;
            for(int i=1;i<=m;i++)
                ans[i] = ch[i];
        }
      return; 
    }
    for(int i=k+1;i<=n;i++){
        ch[num+1] = i;
        dfs(i,num+1);
    }
}
int main(int argc, char const *argv[])
{   int i,j;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(~scanf("%d%d",&n,&m)==2){
        if(n==0&&m==0)
            break;
        for(i=1;i<=n;i++)scanf("%d",&node[i]);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&w[i][j]);
        minians = INF;
        for(int i=1;i<=n;i++){
            ch[1] = i;
            dfs(i,1);
        }
        printf("%d\n",ans[1]);
        for(int i=2;i<=m;i++)
        printf("%d\n",ans[i]);
    printf("\n");
    }
    return 0;
}