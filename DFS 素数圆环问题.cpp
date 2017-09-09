#include <bits/stdc++.h>
using namespace std;
int array[25];
int vis[25];
int n,m;
int is_prime(int x1,int x2){
	int sum = x1+x2;
      for(int i=2;i<=sqrt(sum);i++)
      	if(sum%i==0)
      		return 0;
      	else
      		return 1;
}
void dfs(int cur){
	if(cur==n && is_prime(array[1],array[cur])){
		if(array[1]==1){
			for(int i=1;i<=n;i++){
				printf("%d ",array[i]);
			}
		    printf("\n");
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(!vis[i]&&is_prime(array[cur-1],i)){
				vis[i] = 1;
				array[cur] = i;
				dfs(cur+1);
				vis[i] = 0;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(~scanf("%d",&n)){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++) array[i] = i;
		dfs(1);
	}
	return 0;
}