//51nod 三个数的和为0
#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	int a[1005];
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					if(a[i]+a[j]+a[k]==0){
						printf("%d %d %d\n",a[i],a[j],a[k]);
					}
				}
			}
		}

	}
	return 0;
}