
         蓝桥杯在线测试 入门训练

………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………
………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………

/*
提交序号	1689995
作者	
提交时间	06-14 22:48:13
评测结果	正确
得分	100
CPU使用	15ms
内存使用	944.0KB
试题名称	入门训练 A+B问题
语言	C++
 */
#include <cstdio>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a;
	int b;
	scanf("%d %d",&a,&b);
	printf("%d\n",a+b);
	return 0;
}

/*
提交序号	1689997
作者	
提交时间	06-14 22:52:23
评测结果	运行超时
得分	90
CPU使用	运行超时
内存使用	840.0KB
试题名称	入门训练 序列求和
语言	C++
 */

#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n;
	long long i;
	long long sum = 0;
	scanf("%lld",&n);
	for(i=0;i<=n;i++)
		sum+=i;
	printf("%lld\n",sum);
	return 0;
}

/*
提交序号	1689998
作者	
提交时间	06-14 22:57:10
评测结果	正确
得分	100
CPU使用	0ms
内存使用	840.0KB
试题名称	入门训练 序列求和
语言	C++
 */
//利用求和公式等差数列的求和公式
#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n;
	long long sum=0;
	scanf("%d",&n);
	sum = n + n*(n-1)/2;
	printf("%lld\n",sum);
		return 0;
}

/*
答案错误
 */
#include <cstdio>
#include <cmath>
#define pi 3.14159265358979323
using namespace std;
int main(int argc, char const *argv[])
{
	double r;
	scanf("%lf",&r);
	printf("%.7lf\n",2*pi*r*r);  //错误 圆的面积是 pi*r*r
	return 0;
}
/*

提交序号	1690001
作者	
提交时间	06-14 23:04:04
评测结果	正确
得分	100
CPU使用	0ms
内存使用	840.0KB
试题名称	入门训练 圆的面积
语言	C++
 */
#include <cstdio>
#include <cmath>
#define pi 3.14159265358979323
using namespace std;
int main(int argc, char const *argv[])
{
	double r;
	scanf("%lf",&r);
	printf("%.7lf\n",pi*r*r);
	return 0;
}

/*
提交序号	1690003
作者	
提交时间	06-14 23:21:47
评测结果	运行超时
得分	30
CPU使用	运行超时
内存使用	61.83MB
试题名称	入门训练 Fibonacci数列
语言	C++
 */
#include <cstdio>
#include <algorithm>
using namespace std;
long long fib(int n)
{
	if(n==1||n==2)
		return 1%10007;  //第一个版本错误是因为没有分清楚 / 和 % 的关系
	else
		return (fib(n-1)+fib(n-2))%10007;
}
int main(int argc, char const *argv[])
{
	long long n;
	scanf("%lld",&n);
	
	return 0;
}
/*
AC version
防止递归超时
 */
#include <cstdio>  
const int mod=10007;  
const int MAXN=1000000+10;  
int ans[MAXN];  
int main()  
{  
    ans[1]=ans[2]=1;  
    int n;  
    scanf("%d",&n);  
    for(int i=3;i<=n;i++)  
        ans[i]=(ans[i-1]+ans[i-2])%mod;  
    printf("%d\n",ans[n]);  
    return 0;  
}  



………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………
………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………


