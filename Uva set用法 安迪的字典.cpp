#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;
set<string> dict;
int main(int argc, char const *argv[])
{
	string buf;
	string s;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(cin>>s){
		for(int i=0;i<s.length();i++)
			if(isalpha(s[i])) s[i] = tolower(s[i]);
		else
			s[i] = ' ';
		stringstream ss(s);
		while(ss>>buf){
			dict.insert(buf);
		}
		for(set<string>::iterator it = dict.begin();it!=dic.end();++it){
			cout<<*it<<endl;
			return 0;
		}
	}
	return 0;
}