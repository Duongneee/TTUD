#include <bits/stdc++.h>
using namespace std;
#define MAX 1000009

int n, m; // số đỉnh, số cạnh
int u, v; // đỉnh 1, 2
vector <int> adj[MAX];
stack <int> S;
int num[MAX], low[MAX];
int cur_num = 0 ;
int res = 0;

void SCC(int u, int pu) {
    low[u] = num[u]= cur_num++;
    S.push(u);
    for(int v: adj[u]) {
        if(v == pu){
            continue;
        }
        if(num[v] == -1){
            SCC(v, u);
            low[v] = min(low[u], low[v]);
        }else{
            low[v] = min(low[u], num[v]);
        }  
    }
     
if(num[u]=low[u]){
        res++;
        while(1) {
           int v = S.top();
            S.pop();
            low[v] = num[v]= 1e9;
            if( u == v){
                break;
            }
        }
     }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <=m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) {
        num[i] = -1;
    }

    for(int i = 1; i <= n; i++) {
        if(num[i] == -1) {
            SCC(i, i);
        }
    }
     cout << res;
     return 0;
}
