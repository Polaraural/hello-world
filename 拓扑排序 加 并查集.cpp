/*
用并查集把成绩相等的人放在一起。
然后根据关系，把他们连起来。
然后拓扑排序。
如果拓扑排序结束之后，拓扑到的边数和输入的边数不同，那么肯定出现环了，那么就是信息错误。0
否则，如果某个时刻出现两个点的入度都为0，那么就出现信息不完整。
其他的就是结果正确了。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
struct list
{
    int u;
    int v;
    int next;
} edge[200000]; 
int head[20000];
int nums;
int ru[20000];
int chu[20000];
int f[20000];
int vis[20001];
void add(int u,int v)  //从u到v---邻接表
{
    ru[v]++; //记录入度
    chu[u]++; //记录出度
    //邻接模板 
    edge[nums].u=u;
    edge[nums].v=v;
    edge[nums].next=head[u]; 
    head[u]=nums++; 
}
void init()
{
    memset(head,-1,sizeof(head));
    nums=0;
    memset(ru,0,sizeof(ru));
    memset(vis,0,sizeof(vis));
    memset(chu,0,sizeof(chu));
}
int fx(int x) 
{
    while(x!=f[x])
        x=f[x];
    return x;
}
int a[20000],b[20000];
char cp[20000];
int main()
{
    int n,m,i;
    while(~scanf("%d%d%*c",&n,&m))
    {
        init();
        int bb;
        bb=m;
        for(i=0; i<=n; i++)f[i]=i; //存放父节点的array
        for(i=1; i<=m; i++)
        {
            scanf("%d %c %d%*c",&a[i],&cp[i],&b[i]);
            if(cp[i]=='=')// 判断等于
            {
                f[fx(a[i])]=fx(b[i]);   
                bb--;   
            } 
        }
        for(i=1; i<=m; i++) 
        {
            int aa,bb; 
            aa=fx(a[i]);    
            bb=fx(b[i]);    
            if(cp[i]=='<')add(aa,bb); //aa---->bb
            if(cp[i]=='>')add(bb,aa); //bb---->aa
        }
        int st=i; 
        int bian=0; 
        int leap=0;  
        int leap2=0;  
        while(1)
        {
            leap=0;
            for(i=0; i<n; i++)
            {
                if(f[i]==i&&ru[i]==0&&!vis[i])
                {

                    leap++;
                    if(leap==1)
                    {
                        vis[i]=1;
                        st=i;
                    }
                }
            }
            if(leap==0)break;
            if(leap>1)leap2=1;
            for(i=head[st]; i!=-1; i=edge[i].next)
            {
                int v=edge[i].v;
                bian++;
                ru[v]--;
            }
        }
        if(bian!=bb)
        {
            cout<<"CONFLICT"<<endl;
            continue;
        }
        if(leap2)
        {
            cout<<"UNCERTAIN"<<endl;
            continue;
        }
        cout<<"OK"<<endl;
    }
    return 0;
}
