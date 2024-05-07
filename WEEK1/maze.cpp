#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int step = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(r - 1, c - 1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[r - 1][c - 1] = true;

    vector<vector<int>> steps(n, vector<int>(m, -1));
    steps[r - 1][c - 1] = 0;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int nx, ny, ux, uy;
    bool foundExit = false;

    while (!q.empty()) {
         ux = q.front().first;
         uy = q.front().second;

        q.pop();

        if (ux == 0 || ux == n - 1 || uy == 0 || uy == m - 1) {
            foundExit = true;
            break;
        }

        for (int l = 0; l < 4; l++) {
            nx = ux + dx[l];
            ny = uy + dy[l];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && a[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                steps[nx][ny] = steps[ux][uy] + 1;
            }
        }
    }

    if (foundExit) {
        cout << steps[ux][uy] + 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}