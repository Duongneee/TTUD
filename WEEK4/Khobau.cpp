//find treasure
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1004

struct Treasure {
    int x;
    int y;
    int c;  //so vang tai diem do
};

Treasure points[MAXN];
int n;
long long f[MAXN]; //fi so vang lon nhat thu duoc khi tu diem dau den diem i


void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].c;
    }

    //sap xep cac diem theo thu tu tang dan
    sort(points, points + n, [](Treasure a, Treasure b) {
            if (a.x == b.x)
                return a.y < b.y;
            else
                return a.x < b.x;
        });
}

void solve() {
    //khoi tao ban dau so luong kho bau cho moi diem
    for (int i = 0; i < n; i++) {
        f[i] = points[i].c;
    }
    for (int i = 0; i < n; i++) {   //xet lan luot tu toa do tu be den lon
        for (int j = 0; j < i; j++) {
            //xet cac toa do nho hon points[i]
            if (points[i].x >= points[j].x && points[i].y >= points[j].y) {
                //neu diem j thoa man dieu kien ve di chuyen
                f[i] = max(f[i], f[j] + points[i].c);
            }
        }
    }

    //lay ket qua cuoi cung
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, f[i]);
    }

    cout << res;
}

int main() {
    input();
    solve();

    return 0;
}
