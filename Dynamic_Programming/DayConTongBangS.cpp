#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

int n, s;
int a[MAX];
int dp[MAX]; // lưu tổng bằng i

int main() 
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= s; i++) {
        dp[i] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = s; j >= a[i]; j--) {
            if(dp[j - a[i]] == 1) {
                dp[i] = 1;
            }
        }
    }
    if(dp[s]) cout << 1;
    else cout << 0;
}