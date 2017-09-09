#include <bits/stdc++.h>
using namespace std;
char map[10][10];
int vis[8];
int n,k;
int total,m;
void dfs(int cur){
	if(k==m){
		total++; //计算总次数
		return;
	}
	if(cur>=n) return;
	for(int j=0;j<n;j++){
		if(!vis[j]&&map[cur][j]=='#'){
			vis[j] = 1;
			m++;
			dfs(cur+1);
			vis[j] = 0;
			m--;
		}
		
	}dfs(cur+1);
}
int main(int argc, char const *argv[])
{   
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(~scanf("%d %d",&n,&k)&&n!=-1&&k!=-1){
		total = 0;
		m = 0;
		for(int i=0;i<n;i++) scanf("%s",&map[i]);
	    memset(vis,0,sizeof(vis));
	dfs(0);
	printf("%d\n",total);
	}
	return 0;
}