#include<bits/stdc++.h>
using namespace std;

int n , M[22][1000000], a[1000000];

void preprocessing(int n){
    for(int i = 0; i < n; i++) {
        M[0][i] = i;
    }

    // j là hàng, i là cột
    for(int i = 1; 1 << i <= n; i++ ) {
        for(int j = 0; j + ( 1 << i ) - 1; j++) {
            M[i][j] = min (M[i-1][j], M[i-1][j+(1<<(i-1))]);
        }
    }
}

int query( int l, int r){
    int k = log2(r-l+1);
    return min(M[k][l], M[k][r-(1<<k)+1]);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(0);

    cin >> n;
    for( int i = 0 ; i< n; i++){
        cin  >> a[i];
    }

    preprocessing(n);

    int k;
    cin >> k;
    int kq = 0;
    for( int i = 0 ; i< k; i++){
        int l,r;
        cin >> l >> r;
        kq = kq + query(l,r);
    }
    cout << kq;

   return 0; 
}