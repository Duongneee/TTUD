#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

int n, m;
int w[MAX], v[MAX];
int f[MAX][MAX]; // Giá trị tối đa khi lấy tới điểm thứ i có khối lượng là j

int main() 
{
    cin >> n >> m; // số lượng gói hàng và Trong lượng tối đa
    for(int i = 1; i <=n; i++) {
        cin >> w[i] >> v[i]; // trọng lượng và giá trị
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ; j++) {
            f[i][j] = v[i];

            if( j < w[i] ) f[i][j] = f[i - 1][j]; // khối lượng tối đa nhỏ hơn khối lượng đang xét
            if( j >= w[i]) {
                f[i][j] = max(f[i -1][j - w[i]] + v[i], f[i - 1][j]);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ; j++) {
            res = max(res, f[i][j]);
        }
    }

    cout << res << "\n";

    return 0;
}