#include <stdio.h>
#include <math.h>
long int btd(char *s)
{
	long int rt = 0;
	int i,n = 0;
	while(s[n])
		n++;
	for(--n,i=n;i>=0;i--)
		rt|=(s[i]-48)<<n-i;
	return rt;
}
int main(int argc, char const *argv[])
{
	char s[32];
	gets(s);
	int i = 0;
	long int num = btd(s);
	for(i=1;i<sqrt(num);i++)
	{
		if(i%num==0)
			{
				flag=1；
		        break;
			}

	}
	if(flag==1)
		printf("是素数\n");
	else
		printf("不是素数\n");
	

	return 0;
}