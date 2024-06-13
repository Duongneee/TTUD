#include <bits/stdc++.h>
using namespace std;

#define MAX 50

// Input data
int N, M, Q; // Number of points, number of vehicles, vehicle capacity
int d[MAX]; // Demand at each delivery point

// Other variables
int Y[MAX]; // Starting point of vehicle k
int X[MAX]; // Next point of point i
int segment; // Number of segments
int res; // Result
bool visited[MAX]; // Whether a point has been visited
int load[MAX]; // Load of vehicle k

bool check_X(int v, int k) {
    if (visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

void TRY_X(int s, int k) {
    for (int v = 0; v <= N; v++) {
        if (check_X(v, k)) {
            visited[v] = true;
            load[k] += d[v];
            X[s] = v;
            segment++;
            if (v == 0) {
                if (k == M) {
                    if (segment == N + M)
                        res++;
                } else {
                    TRY_X(Y[k + 1], k + 1);
                }
            } else {
                TRY_X(v, k);
            }
            visited[v] = false;
            segment--;
            load[k] -= d[v];
        }
    }
}

bool check_Y(int v, int k) {
    if (visited[v]) return false;
    return true;
}

void TRY_Y(int k) {
    for (int v = Y[k - 1] + 1; v <= N; v++) {
        if (check_Y(v, k)) {
            visited[v] = true;
            Y[k] = v;
            segment++;
            load[k] += d[v];
            if (k == M) {
                TRY_X(Y[1], 1);
            } else {
                TRY_Y(k + 1);
            }
            visited[v] = false;
            Y[k] = 0;
            segment--;
            load[k] -= d[v];
        }
    }
}

int main() {
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> d[i];
    }
    res = 0;
    Y[0] = 0;
    segment = 0;
    memset(visited, false, sizeof(visited));
    memset(load, 0, sizeof(load));

    TRY_Y(1);
    cout << res << endl;
    return 0;
}
