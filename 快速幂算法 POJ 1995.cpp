// POJ 1995
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll qpow_mod(ll a,ll b,ll mod){
    if(a==0) return 0;
    ll ans = 1;
    while(b){
      if(b&1) ans = (ans%mod)*(a%mod);
      b>>=1;
      a*=a%=mod;
    }
    return ans%mod;
}
int main(int argc, char const *argv[])
{
    int T;
    int m,n;
    ll sum;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&T);
    while(T--){
        sum = 0;
        scanf("%d",&m);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            sum = sum + qpow_mod(a,b,m);
        }
        printf("%lld\n",sum%m);
    }
    return 0;
}