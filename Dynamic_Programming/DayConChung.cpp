#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

int n, a[MAX];
string x, y;
int f[MAX][MAX]; // Độ dài dãy con chung dài nhất lấy từ i phẩn tử đầu tiên của dãy 1 và j phần tử của dãy thứ 2

int main()
{   
    cin >> x >> y;
    int n = x.size();
    int m = y.size();

    for(int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= m; j++) {

            if(x[i] == y[j]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                }
                else { 
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    

    cout << f[n][m];
    return 0;
}