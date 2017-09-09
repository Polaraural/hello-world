#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 101;
int n;

int main() {
	string file[maxn];
	int cmax;
	while (scanf("%d", &n) != EOF) {
		printf("------------------------------------------------------------\n");
		cmax = 0;
		for (int i = 0; i < n; i++) {
			cin >> file[i];
			cmax = max(cmax, (int)file[i].size());
		}
		int col = 62 / (cmax + 2);
		int row = ceil(1.0 * n / col);
		sort (file, file + n);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				//	printf("%s", file[i * row + j]);
				int t = j * row + i;
				if (t >= n)
					continue;
				cout << file[t];
				int k = cmax - file[t].size();
				while (k--)
					printf(" ");
				if (j != col - 1)
					printf("  ");
			}
			if (i <= row - 1)
				printf("\n");
		}
	}
	return 0;
}

//version 2.0
//version 2.0
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 100000;
string f[maxn];
int cmax;
int len;
int main(int argc, char const *argv[])
{
    int n;
    int col;
    int row;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(~scanf("%d",&n)){
        col = 0;
        row = 0;
        cmax = 0;  //注意cmax 要清0.
        for(int i=0;i<n;i++){
            cin >> f[i];
            cmax = max(cmax,(int)f[i].length());
        }
        col = (60 - cmax)/(cmax + 2) + 1;
        row = (n - 1)/col + 1;
        //printf("col = %d\n",col);
        //printf("row = %d\n",row);
        for(int k=0;k<60;k++)
        printf("-");
        printf("\n");
        sort(f,f+n);
        int i,j;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                int t = j*row + i;
                if(t<n) cout<<f[t];
                len = cmax - f[t].size();
                while(len--) 
                    printf(" ");
                if(j!=col-1) 
                    printf(" ");
            }
            if(i<=row-1)
            printf("\n");
        }

    }
    return 0;
}