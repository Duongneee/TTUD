#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int n;
int a[MAX];
int s[MAX]; // lưu tổng lớn nhất tới phần tử thứ i
int res;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    s[1] = a[1];

    for(int i = 2; i <= n; i++){
        if(s[i - 1] < 0) {
            s[i] = a[i];
        }
        else {
            s[i] = s[i - 1] + a[i];
        }
        if(res < s[i]) res = s[i];
    }
    cout << res;
    return 0;
}