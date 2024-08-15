#include <bits/stdc++.h>
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long
using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<vector<int>> adj(N + 1);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= A[i]; ++j) {
            if (i + j <= N) {
                adj[i].push_back(i + j);
            }
        }
    }

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, -1));
    for (int start = 1; start <= N; ++start) {
        queue<int> q;
        q.push(start);
        dist[start][start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (dist[start][neighbor] == -1) {
                    dist[start][neighbor] = dist[start][node] + 1;
                    q.push(neighbor);
                }
            }
        }
    }

    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        cout << dist[X][Y] << endl;
    }
}

int32_t main() {
    IO;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
