#include <cstdio>
#include <cstring>
#include <list>
using namespace std;
const int maxn = 100000 + 10;
list <char> s;
int main(int argc, char const *argv[])
{
    char str[maxn];
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%s",str)!=EOF){
        list <char>::iterator it = s.begin();
        int n = strlen(str);
        for(int i=0;i<n;i++){
            char ch = str[i];
            if(ch == '[') it = s.begin();
            else if(ch == ']') it = s.end();
            else{
                it = s.insert(it,ch);
                it++;
            }
        }
        for(it=s.begin();it!=s.end();it++){
            printf("%c",*it);
        }
        s.clear();
        printf("\n");
    }

    return 0;
}