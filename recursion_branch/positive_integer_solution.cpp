// x1 + x2 + .... + xk + xk+1 + ... 
#include <bits/stdc++.h>
using namespace std;
#define MAX 1009

int n, M;
int a[MAX];
int T;

// Hàm kiểm tra nếu giá trị v có thể thêm vào vị trí k được không
int check(int v, int k) {
    if (k < n) return 1;
    return T + v == M;
}

// Hàm in ra dãy hiện tại
void solution() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

// Hàm thử các giá trị tại vị trí k
void TRY(int k) {
    for (int v = 1; v <= M - T - (n - k); v++) {
        if (check(v, k)) {
            a[k] = v;
            T = T + v;
            if (k == n) solution();  
            else TRY(k + 1);
            a[k] = 0;
            T = T - v;
        }
    }
}

// Hàm chính
int main() {
    n = 3; // Số lượng phần tử trong dãy
    M = 6; // Tổng mục tiêu
    T = 0; // Tổng hiện tại
    TRY(1); // Bắt đầu thử từ vị trí thứ nhất
    return 0;
}
