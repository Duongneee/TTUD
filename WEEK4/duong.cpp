#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001



long long n, a[MAX];
long long SumChan = 0;
long long SumLe = 1000000;
long long sum[MAX];

int main(){
    cin >> n;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    sum[0] = 0;
    long long res = INT_MIN;
    for(long long i = 1; i < n; i++){
        sum[i] = sum[i - 1] + a[i];
        if(sum[i] % 2 == 0){
            res = max(res, sum[i] - SumChan);
            SumChan = min(SumChan, sum[i]);
        }
        else{
            if(SumLe == 1000000 ){
                SumLe = sum[i];
            }
            res = max(res, sum[i] - SumLe);
            SumLe = min(SumLe, sum[i]);
        }
    }


    cout << res << "\n";
    return 0;
}
