// There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0. 
// Input
// Line 1 contains n and k (1≤n≤11,1≤k≤10)
//  Line i+1 (i=1,2,…,2n+1) contains the (i−1)
// th
//  line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
// Output
// Unique line contains the length of the shortest route.
// Example
// Input
// 3  2
// 0  8  5  1  10  5  9
// 9  0  5  6  6  2  8
// 2  2  0  3  8  7  2
// 5  3  4  0  3  2  7
// 9  6  8  7  0  9  10
// 3  8  10  6  5  0  2
// 3  4  4  5  2  2  0
// Output
// 25
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 25 + 5;

int n, cap; // số lượng người và tải trọng của xe khách
int x[MAXN], x_opt[MAXN]; // Kết quả tốt nhất
int cur_load = 0, cur_cost = 0, opt_cost = INT_MAX; // tải trọng hiển tại, chi phí hiện tại, chi phí tốt nhất
int cmin = INT_MAX; // trọng lượng nhỏ nhất trong ma trận
int C[MAXN][MAXN]; // ma trận
bool visited[MAXN] = {false}; // đánh dấu các điểm đã được thăm

// nhập ma trận
void input() {
    cin >> n >> cap;
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            cin >> C[i][j];
            if (i != j)
                cmin = min(cmin, C[i][j]);
        }
    }
}

// Kiểm tra i có thể cho lên xe hay không
bool is_cand(int i) {
    if (visited[i]) //điểm i đã được thăm
        return false;
    if (i > n) // điểm i đã là điểm đích thì kiểm tra xem có thăm điểm i trước n chưa
        return visited[i - n];
    if (i <= n) // nếu i đứng trước n
        return cur_load < cap; // kiểm tra tải trọng hiện tại
    return true; // trả về true nếu không thuộc trường hợp nào trước đó
}

void TRY(int k) {
    for (int i = 1; i <= 2 * n; i++) { //duyệt các điểm trong hành trình
        if (is_cand(i)) { // nếu điểm đó có thể ghé thăm
            x[k] = i; // đánh dấu i là điểm thứ k trong hành trình
            visited[i] = true; // đánh dáu điểm i đã đi qua
            if (i <= n) 
                cur_load++; // nếu i là điểm xuất phát thì đánh dấu tải trọng xe khách tăng lên 1
            else
                cur_load--; //nếu không thì giảm đi 1 (Khách xuống xe)
            cur_cost += C[x[k - 1]][i]; // Tính toán chi phí hiện tại

            if (k == 2 * n) { // nếu k là điểm cuối hành trình rồi
                if (cur_cost + C[i][0] < opt_cost) {
                    opt_cost = cur_cost + C[i][0];
                    for (int j = 0; j <= 2 * n; j++)
                        x_opt[j] = x[j]; // lưu trữ hành trình tốt nhất
                }
            } else { // nếu chưa tới cuối
                // tính toán thử xem chi phí nhỏ nhất có thể có có nhỏ hơn chi phí nhỏ nhất hiện có không
                if (cur_cost + (2 * n - k + 1) * cmin < opt_cost) {
                    TRY(k + 1);
                }
            }
            // quay lui
            visited[i] = false;
            cur_cost -= C[x[k - 1]][i];
            if (i <= n)
                cur_load--;
            else
                cur_load++;
        }
    }
}

int main() {
    input();
    x[0] = 0;
    TRY(1);
    cout << opt_cost << endl;
    return 0;
}