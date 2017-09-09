//并查集判断联通
/*
上次Gardon的迷宫城堡小希玩了很久（见Problem B），
现在她也想设计一个迷宫让Gardon来走。
但是她设计迷宫的思路不一样，首先她认为所有的通道都应该是双向连通的，
就是说如果有一个通道连通了房间A和B，
那么既可以通过它从房间A走到房间B，
也可以通过它从房间B走到房间A，
为了提高难度，小希希望任意两个房间有且仅有一条路径可以相通（除非走了回头路）。
小希现在把她的设计图给你，让你帮忙判断她的设计图是否符合她的设计思路。
比如下面的例子，前两个是符合条件的，
但是最后一个却有两种方法从5到达8。 
Input
输入包含多组数据，每组数据是一个以0 0结尾的整数对列表，
表示了一条通道连接的两个房间的编号。
房间的编号至少为1，且不超过100000。
每两组数据之间有一个空行。 
整个文件以两个-1结尾。 
Output
对于输入的每一组数据，输出仅包括一行。
如果该迷宫符合小希的思路，
那么输出"Yes"，否则输出"No"。 
Sample Input
6 8  5 3  5 2  6 4
5 6  0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0

-1 -1
Sample Output
Yes
Yes
No
*/


//先上并查集模板
int find(int x)
{
    int r = x;
    while(father[r]!=r)
    r = father[r];
    return r;
}
/*
int find(int x)
{
    if(father[x] == x)
    return x;
    else
    return father[x] =find(father[x]);
}
*/

void join(int x,int j)
{
    int fx = find(x),fy = find(y);
    if(fx!=fy)
    father[fx] = fy;
}

void Union(int x,int y)
{
    int rx,ry;
    rx = find(x);
    ry = find(y);
    father[rx] = ry;
}


//
#include <iostream>
#include <stdio.h>
using namespace std;
#define M 100010
int pre[M]; 
int cnt[M]; 
int flag=0; 
int global_edges=0; 
int _find(int node){   //寻找父节点
    if(node==pre[node]) 
    	return node; 
    else return  
    	pre[node]=_find(pre[node]); 
}
int _union(int a,int b)  //将a b连接
{
    if(flag)
    	return 1;
    int p=_find(a);
    int q=_find(b);
    if(p==q)
    	return 1;
    else
    {
        pre[a]=b;
        global_edges++;
        return 0;
    }
}
int main(int argc, char *argv[])
{
    int Yflag=0;
   // freopen("1272.in","r",stdin);
    int a,b;
    for(int i=1;i<M;++i)  //初始化
    {    
    	 pre[i]=i;
         cnt[i]=0;
    }
    while(scanf("%d %d",&a,&b))
    {
        if(a==-1&&b==-1)
        	return 0;
        else if(a==0&&b==0)
        {
            int sum=0;
            for(int i=1;i<M;++i)
            {
                sum+=cnt[i];
            }
            if(Yflag==0)
            	printf("Yes\n");
            else if(flag)
            	printf("No\n");
            else if(sum!=global_edges+1)
            	printf("No\n");
            else
                printf("Yes\n");
            flag=0;
            global_edges=0;
            for(int i=1;i<M;++i)
            {    pre[i]=i;
                cnt[i]=0;
            }
            Yflag=0;
        }
        else
        {
            Yflag=1;
            if(a<b)
                flag=_union(a,b);
            else
                flag=_union(b,a);
            if(cnt[a]==0)
            	cnt[a]++;
            if(cnt[b]==0)
            	cnt[b]++;
        }
    }
    return 0;
}


//version 2
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 100005;
int a,b;
int father[M];       //记录父节点 
bool circle;         //判断是否存在环 
bool visit[M];       //用来记录顶点数  
int edgenum,vnum;    //分别表示边数，顶点数 
void initial( ) //初始化  初始都不联通
{
     for( int i=0 ; i<M ; i++ )
          father[i] = i,visit[i]=false; 
     circle = false;  
     edgenum = vnum = 0;      
}

int find(  int x )//找到父节点
{
    return x == father[x] ? x : father[x] = find(father[x]);     //找祖先节点 + 路径压缩 
}

void merge( int a ,int b ) //将a b两个节点连接起来 并且判断是否成环
{
     if( a == b )
         circle = true;
     int x , y;
     x = find(a);
     y = find(b);
     if( x != y ){
         father[x] = y;
         edgenum++;       //引出一条边 
     }
     else
         circle = true;   //x==y，说明他们是同一个祖先，一旦连通便与祖先3者成环 
}

int main()
{
    while( true ){
           initial( );
           scanf("%d%d",&a,&b);
           if( a==0 && b==0 ){     //为空树 
               printf("Yes\n");       
               continue;
           }
           if( a==-1 && b==-1 )
               break;
           visit[a] = true;
           visit[b] = true;
           merge( a,b );
           while( true ){
                  scanf("%d%d",&a,&b);
                  if( a==0 && b==0 )
                      break;
                  visit[a] = true;
                  visit[b] = true;
                  merge( a , b );  //构造树      
           }
           for( int i=0 ; i<M ; i++ )
                if( visit[i] )  
                    vnum++;  //顶点数   
           if(  !circle && edgenum+1 == vnum ) //不存在环并且保证图是联通的
               printf("Yes\n");
           else
               printf("No\n");
    }     
    return 0;
}


