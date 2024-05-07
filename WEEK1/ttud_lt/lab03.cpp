#include<bits/stdc++.h>
using namespace std;

int main() {
    int count = 0;
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a , a + n);

    int i = 0 , j = n - 1 ;

    while(i < j) {
        if( a[i] + a[j] == q) {
            count++;
            i++;
            j--; 
        }
        else if(a[i] + a[j] > q) {
            j--;
        }
        else if(a[i] + a[j] < q) {
            i++;
        }
    }

        cout << count;
        return 0;

}