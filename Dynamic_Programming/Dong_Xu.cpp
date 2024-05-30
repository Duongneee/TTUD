#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

int n, S;
int a[MAX];
int f[MAX][MAX]; // thu được số tiền s 

int main()
{
    cin >> n >> S;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0][0] = 1;
    for(int i = 1; i <= n ; i++) {
        for(int s = 0; s <= S; s++) {
            f[i][s] = f[i - 1][s];
            if( s > a[i]) {
                f[i][s] = f[i][s] + f[i][s - a[i]];
            }
        }
    }

}