#include<bits/stdc++.h>
using namespace std;
#define MAX 1009

int n, cap; // số lượng người, tải trọng của xe
int x[MAX], x_opt[MAX]; //
int c[MAX][MAX];
int c_min = 100;
int opt_cost = 1000; // chi phí tốt nhất
int cur_cost; // chi phí hiện tại
int cur_load; //
bool visited[MAX] = {false};

bool check(int i, int k) { // kiểm tra có thể ghé thăm i ở lần k được không
    if (visited[i]) {
        // điểm i đã ghé qua
        return false;
    } else if (i > n) {
        // điểm i là điểm đích
        return visited[i - n]; // nếu mà visited i là true thì hành khách đã lên
    } else {
        // i là điểm xuất phát
        if (cur_load + 1 > cap)
            return false;
    }
    return true;
}

void TRY(int k) { // lần thăm thứ k
    for (int i = 1; i <= 2 * n; i++) {
        if (check(i, k)) {
            // có thể ghé thăm
            visited[i] = true;
            x[k] = i;
            if (i <= n) {
                cur_load++;
            } else {
                cur_load--;
            }
            cur_cost += c[x[k - 1]][i]; // điểm trước đó tới điểm hiện tại

            if (k == 2 * n) {
                if (cur_cost + c[i][0] < opt_cost) {
                    opt_cost = cur_cost + c[i][0];
                }
            } else { // chưa tới điểm cuối
                if (cur_cost + c_min * (2 * n + 1 - k) < opt_cost) {
                    TRY(k + 1);
                }
            }

            if (i <= n) {
                cur_load--;
            } else {
                cur_load++;
            }
            visited[i] = false;
            cur_cost -= c[x[k - 1]][i];
            x[k] = 0;
        }
    }
}

int main() {
    cin >> n >> cap;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if (i != j)
                c_min = min(c_min, c[i][j]);
        }
    }

    cur_cost = 0; // khởi tạo cur_cost
    cur_load = 0; // khởi tạo cur_load
    x[0] = 0; // bắt đầu từ điểm xuất phát
    TRY(1);
    cout << opt_cost;
    return 0;
}
