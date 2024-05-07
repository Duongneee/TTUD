#include <bits/stdc++.h> 
using namespace std;

    int n;
    int m;
    int a[1000001];
    int s[1000001];

int main() 
{ 

    s[0] = 0;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int k = 1; k <= n; k++ ) {
        s[k] = s[k-1] + a[k]; 
    }
    
    cin >> m;
    
    for(int j = 0 ; j < m; j ++) {
        int k, l;
        cin >> k >> l;
        cout << s[l] - s[k - 1] << "\n";
    }
    
    return 0;
    
}