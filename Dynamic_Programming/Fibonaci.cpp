// Đầu vào là 1 số n
// Tính Fibonaci của n : F(n);

// Công thức : F(n) = F(n - 1) + F(n - 2)
// F[1] = 1; F[0] = 1

#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

int n;
int f[MAX];

int Fibonaci(int x) {
    for(int i = 0; i <= x; i++) {
        if(i == 0 || i == 1){
            f[i] = 1;
        } else {
            f[i] = f[i - 1] + f[i - 2];
        }
    }
    return f[x];
}

int main()
{
 cin >> n;
 Fibonaci(n);
 cout << Fibonaci(n);
 return 0;
}