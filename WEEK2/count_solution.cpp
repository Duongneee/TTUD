#include<bits/stdc++.h>
using namespace std;

int n, M;
int a[1001],  count_so = 0, b = 0;

void solution_count(int k) {
    for(int i = 1; i <= (M - b)/a[k]; i++) {
        b = b + i * a[k];
        if(k == n && b == M) {
            count_so +=1;
        }
        if(k < n && b < M) {
            solution_count(k + 1);
        } 
           b = b - i * a[k]; 
    }
}

int main() {
    cin >> n >> M;
    for(int i = 1; i <= n; i++) {
       cin >> a[i];
    }
    solution_count(1);
    cout << count_so << "\n";
    return 0;
}