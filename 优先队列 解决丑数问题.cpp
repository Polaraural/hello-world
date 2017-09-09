#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int coffe[3] = {2,3,5};
int main( )
{
    priority_queue<LL,vector<LL>,greater<LL> >pq;
    set<LL> s;
    pq.push(1);
    s.insert(1);
    for(int i=0; ;i++){
        LL x = pq.top();
        pq.pop();
        if(i==1500){
            cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
            break;
        }
        for(int j=0;j<3;j++){
            LL x2 = x * coffe[j];
            if(!s.count(x2)){
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
    return 0;
}