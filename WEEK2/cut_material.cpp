#include <bits/stdc++.h>
using namespace std;

int hi[10], wi[10]; // chiều dài chiều rộng của miếng k

int H, W, n; // chiều dài, chiều rộng, số miếng
bool mark[10][10]; // đánh dấu xem đã cắt chưa

//check xem có cắt được không
bool check(int vx, int vy, int vo, int k) {
    int wk, hk;
    if (vo == 0) { // không xoay
        wk = wi[k];
        hk = hi[k];
    } else { // có xoay
        wk = hi[k];
        hk = wi[k];
    }

    // Nếu có cái là True rồi thì không được 
    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
            if (mark[i][j]) {
                return false;
            }
        }
    }

    return true;
}

// dùng để đánh dấu
void doMark(int vx, int vy, int vo, int k, bool markValue) {
    int wk, hk;
    if (vo == 0) {
        wk = wi[k];
        hk = hi[k];
    } else {
        wk = hi[k];
        hk = wi[k];
    }

// đánh dấu
    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
            mark[i][j] = markValue;
        }
    }
}

void TRY(int k) {
    if (k == n) {
        cout << 1 << endl;
        exit(0);
    }
    
    for (int vo = 0; vo <= 1; vo++) {
        int wk, hk;
        if (vo == 0) {
            wk = wi[k];
            hk = hi[k];
        } else {
            wk = hi[k];
            hk = wi[k];
        }
        for (int vx = 0; vx <= W - wk; vx++) {
            for (int vy = 0; vy <= H - hk; vy++) {
                if (check(vx, vy, vo, k)) {
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

    for (int i = 0; i < n; i++) {
        cin >> hi[i] >> wi[i];
    }

    TRY(0);
    cout << 0 << endl;

    return 0;
}