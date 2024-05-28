#include <bits/stdc++.h>

using namespace std;
int n, m, sum = 0, a[1000001];

struct SparseTable
{
    int n;
    int table[20][1000000];
    // 20 hàng là min của các dãy con độ dài 2, 4, 8, 16, ...
    SparseTable(int arr[], int n)
    {
        this->n = n;

        for (int i = 0; i < n; i++)
            table[0][i] = arr[i];

        for (int k = 1; k <= 19; k++)
            for (int i = 0; i + (1 << k) - 1 < n; i++)
                table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
    }

    int query(int left, int right)
    {
        int len = right - left + 1;
        int k = log2(len);
        return min(table[k][left], table[k][right - (1 << k) + 1]);
    }
};

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SparseTable spare_table(a, n);
    cin >> m;
    int temp_l, temp_r;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp_l >> temp_r;
        sum += spare_table.query(temp_l, temp_r);
    }

    cout << sum << endl;
    return 0;
}