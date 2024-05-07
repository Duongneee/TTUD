#include <bits/stdc++.h>
using namespace std;

pair<int, int> tmp[1009];
int a[1009][1009], h[1009][1009];

int main()
{   
    set<int> S;
    int n, m, res, l, r;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            h[i][j] = 0;
            if (a[i][j] == 1)
                h[i][j] = h[i - 1][j] + a[i][j];
        }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            tmp[j] = {h[i][j], j};

        sort(tmp + 1, tmp + m + 1);
        S.clear();

        S.insert(m + 1);
        S.insert(0);

        for (int j = 1; j <= m; ++j)
        {
            auto it = S.lower_bound(tmp[j].second);
            r = *it;
            it--;
            l = *it;

            res = max(res, (r - l - 1) * tmp[j].first);
            // r - l - 1 vì những chỉ số thêm vào sau đó sẽ auto là của
            // các cột có chiều cao lớn hơn nên sẽ vẫn thỏa mãn với cột này để nhân diện tích
            S.insert(tmp[j].second);
        }
    }

    cout << res;
    return 0;
}
