#include<bits/stdc++.h>
using namespace std;
#define MAX 50

int hi[10], wi[10]; // chiều dài chiều rộng của miếng k
int H, W, n; // chiều dài, chiều rộng, số miếng
bool mark[10][10]; // đánh dấu xem đã cắt chưa

bool check(int vx, int vy, int vo, int k){
     int wk, hk;
    if (vo == 0) {
        wk = wi[k];
        hk = hi[k];
    } else {
        wk = hi[k];
        hk = wi[k];
    }
        // Nếu có cái là True rồi thì không được 
    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j <   vy + hk; j++) {
            if (mark[i][j]) {
                return false;
            }
        }
    }

    return true;   
}

void doMark(int vx, int vy, int vo,int k, bool b){
    int wk, hk;
    if (vo == 0) {
        wk = wi[k];
        hk = hi[k];
    } else {
        wk = hi[k];
        hk = wi[k];
    }

    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
                mark[i][j] = true;
        }
    }
}

void TRY(int k){
    int wk, hk;
    for(int v = 0; v <=1; v++){
        if(v == 0){
            wk = wi[k];
            hk = hi[k];
        } else {
            wk = hi[k];
            hk = wi[k];
        }
        if(k == n){
            cout << 1 << endl;
            exit(0);
        }
        for(int i = 1; i <= W - wk; i++){
            for(int j = 1; j <= H - hk; j++){
                if(check(i, j, v, k)) {
                    doMark(i,j,v,k,true);
                    TRY(k + 1);
                    doMark(i,j,v,k,false);
                }
            }
        }
    }
}

int main(){
    cin >> W >> H >> n;
    for (int i = 1; i <= n; i++) {
        cin >> hi[i] >> wi[i];
    }
    TRY(1);
    cout << 0 << endl;
    return 0;
}