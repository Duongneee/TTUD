#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int n;
int a[N];
int tree[N*4];

void buildtree(int id, int l, int r){
    if(l == r){
        a[id] = a[l];
        return;
    }
    int m = (l + r)/2;
    buildtree(id * 2, l , m);
    buildtree(id*2 + 1, m + 1, r);
    tree[id] = max (tree[id*2], tree[id * 2 + 1]);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    return 0;
}