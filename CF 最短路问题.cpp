#include <cstdio>  
#include <algorithm>  
#include <cstring>  
#include <cstdlib>  
#include <iostream>  
using namespace std;  
  
int main()   
{  
    static int aa[51][51];  
    int n, i, j, x, y, s, t, good;  
    scanf("%d", &n);  
    for (i = 0; i < n; i++)  
    {  
        for (j = 0; j < n; j++)  
        {  
            scanf("%d", &aa[i][j]);  
        }  
    }  
    for (x = 0; x < n; x++)  
    {  
        for (y = 0; y < n; y++)   
        {  
            if (aa[x][y] == 1)  
            {  
                continue;  
            }  
            good = 0;  
            for (s = 0; s < n; s++)  
            {     
                for (t = 0; t < n; t++)  
                {     
                    if (aa[x][s] + aa[t][y] == aa[x][y])  
                    {  
                        good = 1;  
                        break;  
                    }  
                }  
            }  
            if (!good)   
            {  
                printf("No\n");  
                return 0;  
            }  
        }  
    }  
    printf("Yes\n");  
    return 0;  
}  





//B 
#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
    LL m,b;
    LL sum;
    LL ans;
    while(cin>>m>>b)
    {
        ans=0;
        for(int i=b;i>=0;i--)
        {
            sum=0;
            LL border=m*(b-i);
            sum=((border+1)*border/2)*(i+1)+(i*(i+1)/2)*(border+1);
            if(sum>ans) ans=sum;
        }
        cout<<ans<<endl;
    }
    return 0;
}

//D
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
typedef long long LL;
#define maxn 10010
#define INF 3e15
LL n,m,s,k;
LL vis[maxn];
LL dis[maxn];
queue<int> q;
struct node
{
    LL x;int y;
}p[maxn];
LL SPFA(){
   for(int i=1;i<=k;i++){
   	 dis[i] = INF; vis[i] = 0; 
   }
   while(!q.empty())
      q.pop();
   	q.push(1);
   	vis[1] = 1;
   	dis[1] = 0;
   	while(!q.empty()){
   		int cur  = q.front();
   		q.pop();
   		vis[cur] = 0;
   		for(int i=1;i<=k;i++){
   			if(cur == i) continue;
   			LL val = INF;
   			int dx = abs(p[cur].x-p[i].x);
   			int dy = abs(p[cur].x-p[i].y);
   			if(dx+dy==1) val=0;
   			else if(dx<=2||dy<=2)
   				val = 1;
   			if(dis[i]>dis[cur]+val){
   				dis[i] = dis[cur] + val;
   				if(!vis[i]){
   					vis[i] = 1;
   					q.push(i);
   		            }
   			   }
   	    }
   	}
   	if(dis[k] == INF) dis[k] = -1;
   	return dis[k];

}

int main(int argc, char const *argv[])
{
	while(cin>>n>>m>>k){
		bool falg = false;
		for(int i=1;i<=k;i++){
			scanf("%lld%lld",&p[i].x,&p[i].y);
            if(p[i].x==n&&p[i].y==m)
            	flag = true;
		}
		if(flag == false){
			p[++k].x = n+1;
			p[k].y = m+1;

		}
		cout<<SPFA()<<endl;
	}
	return 0;
}

