using namespace std;  
const int N = 100005;  
const int M = 2010;  
const int inf = 2147483647;  
const int mod = 2009;  
int  a[N],b[N], f[N], d[N];    // f[i]用于记录 a[0...i]的最大长度   
int bsearch(const int *f, int size, const int &a)   
{   
    int  l=0, r=size-1;   
    while( l <= r )  
    {   
        int  mid = (l+r)>>1;   
        if( a >= d[mid-1] && a < d[mid] )   
            return mid;                // >&&<= 换为: >= && <   
        else if( a < d[mid] )   
                r = mid-1;   
        else l = mid+1;   
    }   
}   
int LIS(const int *a, const int &n)  
{   
    int  i, j, size = 1;   
    d[0] = a[0]; f[0] = 1;   
    for( i=1; i < n; ++i )  
    {   
        if( a[i] < d[0] )             // <= 换为: <   
            j = 0;                 
        else if( a[i] >= d[size-1] ) // > 换为: >=    
            j = size++;              
        else   
            j = bsearch(d, size, a[i]);   
  
        d[j] = a[i]; f[i] = j+1;   
    }   
    return size;   
}   