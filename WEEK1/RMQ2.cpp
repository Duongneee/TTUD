//C++ 
#include <bits/stdc++.h> 
using namespace std;
#define Max 1000000
int a[Max];
int s[22][Max];

void create(int n){
    int flag = log2(n) + 1;
    for( int i = 0 ; i <n; i++){
        s[0][i] = a[i];
    }
    for ( int j = 1; j < flag ; j++){
        for( int i = 0; i+(1<<j)-1 <n; i++){
            s[j][i] = min (s[j-1][i], s[j-1][i+(1<<(j-1))]);
        }
    }
}

int query( int l, int r){
    int k = log2(r-l+1);
    return min(s[k][l], s[k][r-(1<<k)+1]);
}
int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for( int i = 0 ; i< n; i++){
        cin  >> a[i];
    }
    create(n);
    int k;
    cin >> k;
    int kq = 0;
    for( int i = 0 ; i< k; i++){
        int l,r;
        cin >> l >> r;
        kq = kq + query(l,r);
    }
    cout << kq;
}