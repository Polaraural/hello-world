#include <bits/stdc++.h>
using namespace std;
#define maxn 2000
int father[maxn*2];
bool flag;
void init(int n){
    for(int i=1;i<=maxn+n;i++)
        father[i] = i;flag = true;
}
int find(int x)
{
    int r = x;
    while(father[r]!=r)
    r = father[r];
    return r;
}
void Union(int x,int y){
    int rx;
    int ry;
    rx = find(x);
    ry = find(y-maxn);
    if(rx==ry){
        flag = false;
        return;
    }
    ry = find(y);
    if(rx!=ry)
       father[rx] = ry;
}
int main(int argc, char const *argv[])
{
    int n,m;
    int t;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&t);
    int i;
    for(i=1;i<=t;++i){
        scanf("%d %d",&n,&m);
        //flag = true;
        init(n);
        for(int j=1;j<=m;j++){
            int a,b;
            scanf("%d %d",&a,&b);
            if(flag){
                Union(a,b+maxn);
                Union(b,a+maxn);
            }
        }
        if(flag){
            printf("Scenario #%d:\n",i);
            printf("No suspicious bugs found!\n");
        }   
        else{
            printf("Scenario #%d:\n",i);
            printf("Suspicious bugs found!\n");
        }
        printf("\n");
   }
   return 0;
}