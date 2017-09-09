#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
struct matrix{
    int a,b;
    matrix(int a=0,int b=0):a(a),b(b){}
}m[26];
stack<matrix> s;
int main(int argc, char const *argv[])
{   
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        int k = name[0] - 'A';
        cin>>m[k].a>>m[k].b;
    }
    string expression; 
    while(cin>>expression){
        bool error = false;
        int ans = 0;
        for(int i=0;i<expression.length();i++){
            if(isalpha(expression[i])) s.push(m[expression[i]-'A']);
            else if(expression[i] == ')'){
                matrix m2 = s.top(); s.pop();  //注意弹出的顺序问题
                matrix m1 = s.top(); s.pop();
                if(m1.b!=m2.a){
                    error = true;
                    break;
                }
                ans += m1.a*m1.b*m2.b;
                s.push(matrix(m1.a,m2.b));
            }
        }
        if(error) printf("error\n");
        else printf("%d\n",ans);
    }
    return 0;
}