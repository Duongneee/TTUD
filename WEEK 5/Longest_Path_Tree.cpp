//C++
/*
Sự miêu tả
Cho cây vô hướng $G = (V, E)$ trong đó $V = \{1,…,N\}$ là tập hợp các nút. Mỗi cạnh $(u,v) \in E$ có trọng số $w(u,v)$. Độ dài của một đường đi được xác định bằng tổng trọng số của các cạnh của đường đi đó. Tìm đường đi cơ bản dài nhất trên $G$.
Đầu vào
Dòng 1: số nguyên dương $N$ ($1 \leq N \leq 10^5$)
Dòng $i + 1$ ($i = 1,…,N-1$): số nguyên dương $u, v, w$ trong đó $w$ là trọng số của cạnh $(u,v)$ (1 ≤ w 100)
đầu ra
Trọng số của đường đi dài nhất trên cây đã cho
Ví dụ
Đầu vào
6
1 3 3
1 6 2
2 6 5
4 5 2
4 6 1
đầu ra
10
*/
#include <bits/stdc++.h> 
using namespace std;

#define MAX 1000009

long n;
long u, v, w[MAX][MAX];
vector<long> adj[MAX];
long visited[MAX];

void init(int v, vector<long> a) {
    for(int i = 0; i < sizeof(a); i++) {
        a[]
    }
}


int main() 
{ 
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w[u][v];
        adj[u].push_back(v);
        adj[v].push_back(u);
        w[v][u] = w[u][v];
    }


}