#include <bits/stdc++.h>

using namespace std;

int n, L1, L2;
int a[1000001], s[1000001];

void input()
{
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

int max_gold()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i >= 1 && i <= L1)
            s[i] = a[i];
        else if (i > L1 && i <= L2)
        {
            int tmp_max = 0;
            for (int j = 1; j <= i - L1; j++)
                tmp_max = max(tmp_max, s[j]);
            s[i] = a[i] + tmp_max;
        }
        else
        {
            int tmp_max = 0;
            for (int j = i - L2; j <= i - L1; j++)
                tmp_max = max(tmp_max, s[j]);
            s[i] = a[i] + tmp_max;
        }
        res = max(res, s[i]);
    }
    return res;
}

int main()
{
    input();
    cout << max_gold() << endl;
    return 0;
}
