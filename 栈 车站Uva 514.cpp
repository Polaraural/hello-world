#include <stack>
#include <cstdio>
using namespace std;
const int maxn = 1000 + 10;
int t[maxn];
int main(int argc, char const *argv[])
{
     int n;
     
     //freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     while(scanf("%d",&n)==1){
       stack<int> s;
       int A=1;
       int B=1;
       for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
       int ok = 1;
        while(B<=n){
         if(A==t[B]) {A++;B++;}
         else if(!s.empty()&&s.top()==t[B]){s.pop();B++;}
         else if(A<=n)  s.push(A++);  
         else{ ok = 0; break;}
       }
       printf("%s\n",ok?"Yes":"No");
     }
    return 0;
}