#include <bits/stdc++.h>
using namespace std;


int n, L1, L2;
int a[1000001], s[1000001];
int res;
int tmp_max;

int main() {
    cin >> n >> L1 >> L2;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <=n ;i++){
        if(i <= L1) {
            s[i] = a[i]; // chỉ lấy được ở ô chính nó
        }
        else if(i > L1 && i <= L2){
            tmp_max = 0;
            for(int j = 1; j<= i - L1; j++){
                tmp_max = max(s[j], tmp_max); // tìm ra giá trị lớn nhất 
                s[i] = a[i] + tmp_max;
            }
        }
        else if( i > L2){
            tmp_max = 0;
            for(int j = i - L2; j <= i - L1; j++){
                tmp_max = max(s[j], tmp_max); // tìm ra giá trị lớn nhất 
                s[i] = a[i] + tmp_max;
            }
        }
        res = max(res, s[i]);
    }
    cout << res;
}