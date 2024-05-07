#include <bits/stdc++.h>

using namespace std;

// Struct lưu trữ các giá trị RMQ
struct RMQ {
    int n;
    vector<vector<int>> sparseTable;
    vector<int> logTable;

    RMQ(const vector<int>& arr) {
        n = arr.size();
        logTable.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            logTable[i] = logTable[i / 2] + 1;
        }

        int logN = logTable[n] + 1;
        sparseTable.resize(n, vector<int>(logN));

        for (int i = 0; i < n; i++) {
            sparseTable[i][0] = arr[i];
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                sparseTable[i][j] = min(sparseTable[i][j - 1], sparseTable[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int k = logTable[r - l + 1];
        return min(sparseTable[l][k], sparseTable[r - (1 << k) + 1][k]);
    }
};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<pair<int, int>> queries(m);

    for (int i = 0; i < m; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Tạo RMQ object từ mảng a
    RMQ rmq(a);

    long long sumQ = 0;

    for (int i = 0; i < m; i++) {
        int l = queries[i].first;
        int r = queries[i].second;

        // Tìm giá trị nhỏ nhất trong đoạn [l, r] và cộng vào tổng Q
        sumQ += rmq.query(l, r);
    }

    cout << sumQ << endl;

    return 0;
}