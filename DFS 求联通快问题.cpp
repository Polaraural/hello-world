#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 105;
char map[maxn][maxn];
int to[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
int m,n;
int sum;
void dfs(int x,int y){
    int tx;
    int ty;
    for(int i=0;i<8;i++){
        tx = x + to[i][0];
        ty = y + to[i][1];
        if(tx>=1&&tx<=m&&ty>=1&&ty<=n){
            if(map[tx][ty] == '@'){
                map[tx][ty] = '*';
                dfs(tx,ty);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(~scanf("%d%d",&m,&n)){
        if(m==0&&n==0) break;
        sum = 0;
        memset(map,0,sizeof(map));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                cin>>map[i][j];
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(map[i][j]=='@'){
                    sum++;
                    map[i][j] = '*';
                    dfs(i,j);
                }
            }
        printf("%d\n",sum);
             
    }
    return 0;
}