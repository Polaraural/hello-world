//Time to Get up
#include <bits/stdc++.h>
using namespace std;
char s[21][7];
int trans(char f[4][7]){
	int t;
	if(f[1][0] == f[2][0] == 'X'){
         if(f[1][3] == f[2][3] == '.'){
         	if(f[0][1] == f[0][2] == 'X'){
         		t = 0; 
         		return t;
         	}
         	else
         	{
         		t = 7; 
         		return t;
         	}	
         }
         else{
         	if(f[0][1] == f[0][2] == '.'){
                  if(f[0][4] == f[0][5] == 'X'){
                  	t =2;
                  	return t;
                  }
                  else{
                  	t= 3;
                  	return t;
                  }
         	}
         	else{
         		if(f[0][4] == f[0][5] =='X'){
         			if(f[3][1] == f[3][2] == 'X'){
         				t = 8;
         				return t;
         			}
         			else{
         				t = 6;
         				return t;
         			}
         		}
         		else{
         			if(f[3][1] == f[3][2] == 'X'){
         				t = 9;
         				return t;
         			}
         			else{
         				t = 5;
         				return t;
         			}
         		}
         	}
         }
	}
	else{
		if(f[1][3] == f[2][3] == 'X'){
			t = 4;
			return t;
		}
		else{
			t = 1;
			return t;
		}
	}
}
int main(int argc, char const *argv[])
{   
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int i;
		for(i=0;i<21;i++)
			for(int j=0;j<7;j++)
				scanf("%c",s); // ????
		char time[4][7];
		int hour[4];
		int num;
		int n=0;
		for(i=0;i<21;i++){
			if(i==0||i==5||i==12||i==17){
				num = 0;
				for(int j=i;j<i+4;j++){
					for(int k=0;k<7;k++){
						s[j][k] = time[num++][k];
					}
				}
				hour[n++] = trans(time[4][7]);
			}
		}
		for(i=0;i<4;i++)
		printf("%d ",hour[i]);

	}
	return 0;
}

//version 2.0
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char a[10][25];
char ch[7][4];

int fun(char c[7][4])//利用数形状的差距直接判断
{
    for(int i=0;i<7;i++)
        for(int j=0;j<4;j++)
    {
        if(c[3][1]=='X' && c[3][2]=='X')
        {
            if(c[0][1]=='.' && c[0][2]=='.')
                return 4;
            if(c[4][0]=='X' && c[5][0]=='X')
            {
                if(c[1][0]=='.' && c[2][0]=='.')
                    return 2;
                if(c[1][3]=='X' && c[2][3]=='X')
                    return 8;
                return 6;
            }
            else
            {
                if(c[1][3]=='.' && c[2][3]=='.')
                    return 5;
                if(c[1][0]=='.' && c[2][0]=='.')
                    return 3;
                return 9;
            }
        }
        else if(c[3][1]=='.' && c[3][2]=='.')
        {
            if(c[1][0]=='X' && c[2][0]=='X')
                return 0;
            if(c[0][1]=='X' && c[0][2]=='X')
                return 7;
            return 1;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        for(int i=0;i<7;i++)
            scanf("%s",a[i]);
        int num=0;
        int coun=0;
        for(int j=0;j<21;j++)
        {
            if(j==4 || j==9 || j==10 || j==11 || j==16)
            {
                continue;
            }
            else
            {
                num++;
            }
            if(num%4==0)//累计四行做一次判断
            {
                for(int i=0;i<7;i++)
                {
                    for(int k=j-3,s=0;k<=j;k++,s++)
                    {
                        ch[i][s]=a[i][k];
                    }
                }
                cout<<fun(ch);
                coun++;
                if(coun==2) cout<<":";
            }
        }
        cout<<endl;
    }
    return 0;
}
