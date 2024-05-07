    #include<bits/stdc++.h>
    using namespace std;

    int main() {
        int n;
        cin >> n;
        int q;
        cin >> q;
        int a[n];
        for(int i = 0; i < n ; i++) {
            cin >> a[i];
        }

        int res = 1;
        int s = 0;
        int l = 0;
        for (int j = 0; j < n ; j++) {
            s = s + a[j];
            while (s > q) {
                s = s - a[l];
                l++;
            }
            res = max(res, j - l + 1);
        }

        cout << res ;
    return 0;
    }