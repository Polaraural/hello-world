#include <string.h>     
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//#define N 3
#define M 10 // 作为分数数组的下标上限
#define maxn 100000
int add;
int N; //n代表的是选手的个数。 
int sum[maxn]={0};//存放总成绩的数组 
int Max[maxn];//存放最大值 
int Min[maxn]; //sum用来保存总分数 max用来保存最大值 min用来保存最小值
float aver[maxn]={0}; //设置浮点型的数组保存平均值 
struct player //定义结构体 包含选手的名字 编号
{
int num;
char name[8];//存放姓名 
int score[M];//存放分数 
};
void Inistplayer(struct player a[],int n)  //输入选手的信息函数
{int i;
printf("编号 姓名\n");
for(i=0;i<n;i++)
scanf("%d %s",&a[i].num,&a[i].name);
}
void Inputscore(int score[],int n) //输入评委给选手打的分数
{int i;
for(i=0;i<n;i++)
//score[i]=1+(int)(10.0*rand()/(RAND_MAX+1.0)); //用生成的随机数代表评委打的分数
{
   scanf("%d",&score[i]);
   if(score[i]<0||score[i]>100)
   {
     printf("输入的数据有误，请重新输入");
     scanf("%d",&score[i]);
   } 
   
}

}
void menu()
{
puts("    ┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
printf("      ┃    **********1.输入选手数据***********  ┃\n");
printf("      ┃    **********2.评委打分***************  ┃\n");
printf("      ┃    **********3.成绩排序***************  ┃\n");
printf("      ┃    **********4.数据查询***************  ┃\n");
printf("      ┃    **********5.追加学生数据***********  ┃\n");
printf("      ┃    **********6.写入数据文件***********  ┃\n");
printf("      ┃    **********7.退出系统***************  ┃\n");
puts("    ┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
} 
void sort(struct player a[],float b[],int n) //排序算法
{int i,k,j,t;
float temp;
char str[8];
for(i=0;i<n;i++)
{k=i;
for(j=i+1;j<n;j++)
if(b[k]>b[j]) k=j;
if(k!=i)
{temp=b[i];
b[i]=b[k];
b[k]=temp;
strcpy(str,a[i].name); 
strcpy(a[i].name,a[k].name); 
strcpy(a[k].name,str); 
t=a[i].num; 
a[i].num=a[k].num; 
a[k].num=t; 
}
}
}
int main() 
{int flag=1,n,i,m,j; 
FILE *fp;
fp = fopen("data.txt","w+"); //读取文件
struct player a[20];
menu();
printf("请输入选手的个数：\n");
scanf("%d",&N);
//system("cls");
add = N-1;
while(flag)
{

printf("你想进行的操作:");
scanf("%d",&n);
system("cls");
switch(n)
{
case 1:menu();
       Inistplayer(a,N);
       printf("\n");
       //system("cls");
       break;
case 2:srand((unsigned)time(NULL));
        menu();
        for(i=0;i<N;i++)
       {
        printf("%d位选手的成绩:",i+1);
        Inputscore(a[i].score,M);
        //for(j=0;j<M;j++)
        //printf("%d ",a[i].score[j]);
        printf("\n");
       }
       printf("\n");
        //system("cls");
        break;
case 3: menu();
        for(i=0;i<N;i++)
        {Max[i]=a[i].score[0];
         Min[i]=a[i].score[0];
         for(j=0;j<M;j++)
        {
         sum[i]+=a[i].score[j];
         if(Max[i]<a[i].score[j]) Max[i]=a[i].score[j];
         if(Min[i]>a[i].score[j]) Min[i]=a[i].score[j];
        }
         aver[i]=(float)(sum[i]-Max[i]-Min[i])/(M-2);
        }
        sort(a,aver,N);
        for(i=0;i<N;i++)
        printf("%s %5.2f\n",a[i].name,aver[i]);
     //system("cls");
        break;
case 4: menu();
        printf("你想查询选手的数据:");
        scanf("%d",&m);
        for(i=0;i<N;i++)
        if(a[i].num==m)
        {
         printf("%d号选手%s总分:%d,最高分%d,最低分%d,平均分%5.2f",a[i].num,a[i].name,sum[i],Max[i],Min[i],aver[i]);
         printf("\n");
        }
        //system("cls");
        break;
case 5: menu();
        printf("请输入要追加的选手数据：\n");
        add += 1;
        if(add>=19)
    {
       printf("你的输入超限。\n");
       break;
    } 
        scanf("%d %s",&a[add].num,&a[add].name);
         //system("cls");
        break;
case 6: menu();
        printf("将数据写入文件中：\n");
        for (i = 0 ; i < add+1 ; i++)
        {
            fprintf(fp,"%d ",a[i].num);
            fprintf(fp,"%s ",a[i].name);
            fprintf(fp,"%d\n",a[i].score);
        }
         //system("cls");
        break;
case 7:exit(0);
        break;
default:flag=0;
}
}
return 0;
}
