//find treasure
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1004

struct keke{
    int x;
    int y;
    int c;
};

keke point[MAXN];
int n; // số lượng vàng
int f[MAXN];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> point[i].x >> point[i].y >> point[i].c;
    }

    sort(point, point + n, [](keke a , keke b){ // a sẽ đứng trước b nếu return true
        if(a.x == b.x){
            return a.y < b.y;
        } else {
            return a.x < b.x;
        }
    });

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < i; j++){
            if(point[i].x >= point[j].x && point[i].y >= point[j].y) {
                f[i] = max(f[i], f[j] + point[i].c);
            }
        }
    }
    int res = INT_MIN;
    for(int i = 0; i < n ; i++){
        res = max(res, f[i]);
    }
    cout << res;
    return 0;
}
