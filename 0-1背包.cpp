/*
输入包含多组测试用例。 
　　每组数据以一个整数n开始，表示每天的食物清单有n种食物。 
　　接下来n行，每行两个整数a和b，其中a表示这种食物可以带给湫湫的幸福值（数值越大，越幸福），b表示湫湫吃这种食物会吸收的卡路里量。 
　　最后是一个整数m，表示湫湫一天吸收的卡路里不能超过m。 

　　 
TechnicalSpecification
TechnicalSpecification

　　1. 1 <= n <= 100 
　　2. 0 <= a,b <= 100000 
　　3. 1 <= m <= 100000 
Output
　　对每份清单，输出一个整数，即满足卡路里吸收量的同时，湫湫可获得的最大幸福值。
Sample Input
3
3 3
7 7
9 9
10
5
1 1
5 3
10 3
6 8
7 5
6
Sample Output
10
20
*/
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 100010
int dp[maxn];
int main(int argc, char const *argv[])
{
	int n=0,m=0;
	while(scanf("%d",&n)==1){
		memset(dp,0,sizeof(dp));
		int luck ;
	    int calorie ;
		for(int i=0;i<n;i++){
            scanf("%d%d",&luck,&calorie);
            for(int j=calorie;j<100010;j++){
                if(luck+dp[j-calorie]>dp[j])
                	dp[j] = luck+dp[j-calorie];
            }   
		}
		scanf("%d",&m);
		printf("%d\n",dp[m]);
	}
	return 0;
}


//0-1 package
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 600
int dp[maxn];
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
	  int n;
	  int empty,fall;
	  scanf("%d%d",&empty,&fall);
	  int sum = fall - empty;
	  scanf("%d",&n);
	  for(int i=0;i<n;i++){
	  	int weight,value;
	  	scanf("%d%d",&weight,&value);
          for(int j=sum;j>=value;--j){
          	dp[j] = max(dp[j],dp[j-value]+weight);
          }
	  }
	  printf("The minimum amount of money in the piggy-bank is %d.\n",dp[]);
	}
	return 0;
}