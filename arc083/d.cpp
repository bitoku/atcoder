#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> edge = a;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (edge[i][j] == a[i][k] + a[k][j]) {
                    edge[i][j] = -1;
                    edge[j][i] = -1;
                    edge[i][k] = a[i][k];
                    edge[k][i] = a[i][k];
                    edge[k][j] = a[k][j];
                    edge[j][k] = a[k][j];
                }
            }
        }
    }
    vector<vector<ll>> dist = edge;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < 0 || dist[k][j] < 0) continue;
                if (dist[i][j] < 0 || dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != dist[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (edge[i][j] < 0) continue;
            result += edge[i][j];
        }
    }
    cout << result << endl;
}