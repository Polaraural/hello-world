//HDU 1061
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n;
ll qpow_mod(int a,int b,int mod){
    if(a==0) return 0;
    ll ans = 1;  //注意 这里是1 不是0
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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll num = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        num = qpow_mod(n,n,10);
        printf("%lld\n",num);
    }
    return 0;
}