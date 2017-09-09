/*
After the 1997/1998 
Southwestern European Regional Contest (which was held in Ulm) a large contest party took place.
 The organization team invented a special mode of choosing those participants that were to assist with washing the dirty dishes. 
 The contestants would line up in a queue, one behind the other. Each contestant got a number starting with 2 for the first one, 3 for the second one, 4 for the third one, and so on, consecutively. 
The first contestant in the queue was asked for his number (which was 2). He was freed from the washing up and could party on, but every second contestant behind him had to go to the kitchen (those with numbers 4, 6, 8, etc). Then the next contestant in the remaining queue had to tell his number. He answered 3 and was freed from assisting, but every third contestant behind him was to help (those with numbers 9, 15, 21, etc). The next in the remaining queue had number 5 and was free, but every fifth contestant behind him was selected (those with numbers 19, 35, 49, etc). The next had number 7 and was free, but every seventh behind him had to assist, and so on. 

Let us call the number of a contestant who does not need to assist with washing up a lucky number. 
Continuing the selection scheme, 
the lucky numbers are the ordered sequence 2, 3, 5, 7, 11, 13, 17, etc. 
Find out the lucky numbers to be prepared for the next contest party. 
Input
The input contains several test cases. Each test case consists of an integer n. 
You may assume that 1 <= n <= 3000.
A zero follows the input for the last test case. 
Output
For each test case specified by n output on a single line the n-th lucky number. 
Sample Input
1
2
10
20
0
Sample Output
2
3
29
83
*/


#include <iostream>
#include <cstdio>
using namespace std;

int ans[3001] = {0}; 
bool que[40010] = {1, 1, 0};  

int main()
{
    int k, i, j, cnt;
    for(k = 0; k < 3001; k++)
    {
        //这个for loop找到下一个未被选中的人
        for(i = ans[k-1]+1; que[i]; i++){}
        ans[k] = i;
        for(j = i+1, cnt = i; j < 40010; j++)
        {
            if(!que[j] && !--cnt)
            {
                que[j] = 1;
                cnt = i;
            }
        }
    }
   // for(i = 1; i < 20; i++) cout<< ans[i] << " ";
   // cout<<endl;
    while(scanf("%d", &i) && i)
    {
        printf("%d\n", ans[i-1]);
    }
    return 0;
}


//Vector 
#include <iostream>
#include <vector>
using namespace std;
vector<int> vt; //创建Vector容器
int main(){
	 for(int i=2;i<=40000;i++)
		vt.push_back(i);  //尾部插入元素
	for(vector<int >::iterator it=vt.begin();;it!=vt.end();) //容器的遍历
	{
		for(vector<int >::iterator it2=it+(*it);it2<vt.end();it2+=(*it))
		{
			it2=vt.erase(it2);//erase 返回的是下一个位置
			it2--;
		}
		it++;
	}
	int t;
	while(cin>>t&&t){
		cout<<vt[t-1]<<endl;
	}  
}