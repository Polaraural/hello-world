// version 1.0 时间复杂度还是很高 一般不用
typedef long long LL;
LL fast_mi(int a,int b,int n){
	int ret = 1;
	while(b--){
		ret = a*ret%n;
	}
	return ret;
}
// version 2.0
int modexp(int a,int b,int n) //计算a^bmodn 
{   
    int ret=1;   
    int tmp=a;   
    while(b)   
    {   
       //基数存在   
       if(b&0x1) ret=ret*tmp%n;   
       tmp=tmp*tmp%n;   
       b>>=1;   
    }   
    return ret;   
}   
//version 3.0 ---> O(logb)
int PowerMod(int a, int b, int c)
{
    int ans = 1;
    a = a % c;
    while(b>0) {
        if(b % 2 = = 1)
        ans = (ans * a) % c;
        b = b/2;
        a = (a * a) % c;
    }
    return ans;
}
// 快速乘法
int qmul(int a,int b){// 根据数据范围可选择long long 
    int ans=0;
    while(b){
        if( b&1)ans+=a;//按位与完成位数为1的判断
        b>>=1;a<<=1;//位运算代替/2和*2
    }
    return ans;
}
//快速乘法取模
//快速乘法取模 
int qmul_mod(int a,int b,int mod){
    int ans=0;
    while(b){
        if((b%=mod)&1)ans+=a%=mod;//这里需要b%=mod 以及a%=mod 
        b>>=1;a<<=1;
    }
    return ans%mod;  //ans也需要对mod取模 
}
//快速幂 a^b 
int qpow(int a,int b){
    if(a==0)return 0;//这是个坑，校赛被坑过，很多网上的实现都没写这一点
    int ans=1;
    while(b){
        if(b&1)ans*=a;//和快速乘法的区别
        b>>=1;a*=a;//区别，同上
    }
    return ans;
}
//以及含有取模的快速幂
int qpow_mod(int a,int b,int mod){
    if(a==0)return 0;
    int ans=1;
    while(b){
        if(b&1)ans=(ans%mod)*(a%mod);//如果确定数据不会爆的话，可写成 ans*=a%=mod;
        b>>=1;a*=a%=mod;//等价于a=(a%mod)*(a%mod)，且将一个模运算通过赋值代替，提高了效率
    }
    return ans%mod;//数据不会爆的话，这里的%运算会等价于第5中不断重复的 ans%mod
}
int qpow_mod(int a,int b,int mod){
    if(!a)return 0;
    int ans=1;
    while(b){
        if(b&1)ans*=a%=mod;//这里的模运算只有一个
        b>>=1;a*=a;//这里的模运算没有了
    }
    return ans%mod;
}