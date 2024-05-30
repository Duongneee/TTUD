#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

int n;
int a[MAX];
int f[MAX]; // lưu giá trị tổng lớn nhất tìm được tại điểm i (f[i])

int main() 
{   cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <=n; i++) {
        if(i == 1) f[i] = a[i] ;
        if(i > 1) {
           f[i] = max(a[i], f[i-1] + a[i]);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
         res = max(res, f[i]);
    }

    cout << res <<"\n";
    return 0;
}