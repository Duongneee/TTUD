#include <bits/stdc++.h>
using namespace std;

int hi[10], wi[10]; // chiều dài, chiều rộng miếng thứ i
int mark[10][10];// đánh dấu 
int H, W, n; // chiều dài chiều rộng miếng to số miếng
int check(int vx, int vy, int vo, int k){
    int wk, hk;
    if(vo = 1){
        wk = hi[k];
        hk = wi[k];
    }
    else {
        wk = wi[k];
        hk = hi[k];
    }
    for(int i = vx; i < vx + wk; i++) {
        for(int j = vy ; j < vy + hk; j++) {
            if(mark[i][j] ) {
                return false;
            }
        }
    }
}

void doMark(int vx, int vy, int vo, int k, bool markVal){
    int wk, hk;
    if(vo = 0){
        wk = wi[k];
        hk = hi[k];
    } else {
        wk = hi[k];
        hk = wi[k];
    }
    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
            mark[i][j] = markVal;
        }
    }
}

void TRY(int k){
    if( k == n){
        cout << 1 << "\n";
        exit(0);
    }
    for(int vo = 0; vo <= 1; vo++) {
        int wk, hk;
        if (vo == 0) {
            wk = wi[k];
            hk = hi[k];
        } else {
            wk = hi[k];
            hk = wi[k];
        }

        for(int vx = 0; vx < W - wk; vx++){
            for(int vy = 0; vy < W - hk; vy++){
                if(check(vx, vy, vo, k)){
                    doMark(vx, vy, vo, k, true);
                    TRY(k + 1);
                    doMark(vx, vy, vo, k, false);
                }                
            }
        }
    }
}

int main() {
    cin >> H >> W;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> wi[i] >> hi[i];
    }
    TRY(0);
    cout << 0 << "\n";
    return 0;
}