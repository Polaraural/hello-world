/*
<cctype>
isdigit(ch); //是否是数字[0-9]
isalpha(ch); //是否是英文字符[a-zA-Z]
islower(ch); //是否是小写字符[a-z]
isupper(ch); //是否是大写字符[A-Z]
 tolower(ch); //转化为小写字符
toupper(ch); //转化为大写字符
*/
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
stack <char> s1; //number of stack
stack <char> s2;
stack <char> s3; //operater of stack
int priority(char ch1,char ch2){
	int x1 = ch1 - '0';
	int x2 = ch2 - '0';
	if(x1<=x2)  
		return 1;
	else 
		return 0; 
}
void transBolan_Expression(string &str){
	string ans = str;
	int len = ans.length();
	for(int i=len-1;i>=0;i--){
		 if(isalnum(ans[i]))
		 	s1.push(ans[i]);
		 if(!isalnum(ans[i])){
		 	if(ans[i] == '('){
		 	while(s2.front()!=')'){
		 		char ch = s2.front;
		 		s1.push(ch);
		 		s2.pop();
		 	}
		 	s2.pop();
		 }
		 s2.push(ans[i]);
		 }
	}
}
int main(int argc, char const *argv[])
{
	int N;
	stirng expression1;
	string expression2;
	scanf("%d",&N);
	while(N--){
		while(cin>>expression1){
			for(int i=0;i<expression1.length();i++){
				if(isalpha(expression1[i])) {
					expression1[i] = expression1[i] - '0';
				}
			}
		}
		while(cin>>expression2){
			for(int i=0;i<expression2.length();i++){
				if(isalpha(expression2[i])) {
					expression2[i] = expression2[i] - '0';
				}
			}
		}
		transBolan_Expression(expression1);
		char s_1[len1];
		int n = 0;
		s2.front() = s_1[n];
		s2.pop(); n++;
		for(int i=len1-1;i>=0;i--){
			if(!isalnum(s_1[i])){
				s3.push(s_1[i]);

			}
		}



	}
	return 0;
}

/*
我现在真的是发现我的垃圾了。
写了这么久代码写的也不整洁
实在是写不下去了
我知道有很多的BUG
但是不知道怎么改
很尴尬
所以去看博客的代码
然后再来改我的代码
唉 实力不足啊
真的是不足啊
*/
