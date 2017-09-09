//UVA 10474 Marble-Problem
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int main(int argc, char const *argv[])
{   
    int number_marbles;
    int numnber_find;
    int a[maxn];
    //int find[maxn];
    int find;
    int kcase = 0;
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    while(~scanf("%d %d",&number_marbles,&numnber_find)){
        if(number_marbles==0&&numnber_find==0) break;
        for(int i=0;i<number_marbles;i++){
            scanf("%d",&a[i]);
        }
        printf("CASE# %d:\n",++kcase);
        //sort(find,find+numnber_find);
        sort(a,a+number_marbles); // from low to high;
        while(numnber_find--){
            scanf("%d",&find);
            int p = lower_bound(a,a+number_marbles,find) - a;
            if(a[p] == find)  printf("%d found at %d\n",find,p+1);
            else printf("%d not found\n",find);
        }
    }
    return 0;
}