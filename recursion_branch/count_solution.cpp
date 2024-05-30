#include<bits/stdc++.h>
using namespace std;
#define MAX 1009
int n, m;
int a[MAX]; 
int T = 0; // lưu tổng hiện tại
int res;

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

bool check(int i, int k){
    if(T + a[k] * i > m) return false;
    return true;
}   


void TRY(int k){ // thử tới hệ số k
    for(int i = 1; i <= (m - T)/a[k]; i++){
        if(check(i , k)){
            T = T + a[k] * i;
        }
        if(k == n && T == m){
            res++;
        }else if(k < n && T < m){
            TRY(k + 1);
        }
        // quay lui
        T = T - a[k] * i;
    }
}

int main(){
    input();
    TRY(1);
    cout << res;
}