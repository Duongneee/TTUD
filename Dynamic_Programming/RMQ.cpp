#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int n;
int a[MAX];
int f[MAX][MAX];
int res;

void PreProcessing(){
    for(int j = 0; (1 << j) < n; j++){
        for(int i = 0; i + ( 1 << j) - 1 < n; i++){
            if(a[f[j - 1][i]] < a[f[j - 1][i + (1 << (j - 1))]]){
                f[j][i]= f[j-1][i];
            }else{
                f[j][i] = f[j - 1][i + (1 << (j - 1))]; 
            }
        }
    }
}

int RMQ(int j, int i){
    int k = log2(j - i + 1);
    int p2k = pow(2,k);
    if(a[f[k][i]] <= a[f[k][j - p2k + 1]]){
        return f[k][i];
    }
    else{
        return f[k][j - p2k + 1];
    }

}

int main(){
    cin >> n;
    for(int i = 0; i<= n ; i++){
        cin >> a[i];
        f[0][i] = i; // lưu chỉ số nhỏ nhất
    }

    return 0;
}