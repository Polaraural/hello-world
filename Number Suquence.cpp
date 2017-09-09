/*
A single positive integer i is given. 
Write a program to find the digit located in the position i in the sequence of number groups S1S2...Sk. 
Each group Sk consists of a sequence of positive integer numbers ranging from 1 to k, written one after another. 
For example, the first 80 digits of the sequence are as follows: 

//11212312341234512345612345671234567812345678912345678910123456789101112345678910 

//Input
The first line of the input file contains a single integer t (1 ≤ t ≤ 10),
the number of test cases, followed by one line for each test case. 
The line for a test case contains the single integer i (1 ≤ i ≤ 2147483647) 
Output
There should be one output line per test case containing the digit located in the position i. 
//Sample Input
2
8
3
//Sample Output
2
2
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define LL long long 
using namespace std;
#define maxn 100000
LL a[maxn];
LL s[maxn];
LL so(LL x,LL d){ //取第d位数字
	while(d--){
		x/=10;
	}
	return x%10;
}
int main(int argc, char const *argv[])
{

	LL n,m,i,j,cla;
	a[1] = b[1] = 1;
	for(int i=2;i<340000;i++){
		a[i] = a[i-1] + (LL)log10((double)i)+1; //规律
		s[i] = s[i-1] + a[i];
	}
    scanf("%d",&cla);
    while(cla--){
    	scanf("%lld",&n);
    	i=0;
    	while(s[i]<n){
    		i++;
    	}
    	m = n - s[i-1];
    	i = 0;
    	while(m<a[i]){
    		i++;
    	}
    	printf("%lld\n",so(i,a[i]-m));
    }
	return 0;
}

