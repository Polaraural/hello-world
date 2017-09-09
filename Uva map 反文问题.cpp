//Uva map 反语字母
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
map<string,int> cnt;
vector<string> words;
//vector<string> ans;
string init(const string& s){
    string ans = s;
    for(int i=0;i<ans.length();i++)
        ans[i] = tolower(s[i]);
    sort(ans.begin(),ans.end());
    return ans;
}
int main(int argc, char const *argv[])
{   
    int n = 0;
    string s;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(cin>>s){
        if(s[0] == '#') break;
        words.push_back(s);
        string r = init(s);
        if(!cnt.count(r)) cnt[r] = 0;
        cnt[r]++;
    }
    vector<string> ans;
    for(int i=0;i<words.size();i++)
        if(cnt[init(words[i])]==1) 
            ans.push_back(words[i]);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<endl;
    return 0;
}