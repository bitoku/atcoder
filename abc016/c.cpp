#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, -1));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] == -1 || dist[k][j] == -1) continue;
                if (dist[i][j] == -1 || (dist[i][j] > dist[i][k] + dist[k][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ll result = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == 2) result++;
        }
        cout << result << endl;
    }
}