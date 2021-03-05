#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> d(n+1, vector<ll>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> d[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            d[i][j] += d[i][j - 1];
        }
        for (int j = 1; j <= n; ++j) {
            d[i][j] += d[i-1][j];
        }
    }
    vector<ll> m(n * n + 1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = i+1; k <= n; ++k) {
                for (int l = j+1; l <= n; ++l) {
                    m[(k - i) * (l - j)] = max(m[(k - i) * (l - j)],
                                               d[k][l] - d[k][j] - d[i][l] + d[i][j]);
                }
            }
        }
    }
    for (int i = 1; i < n * n; ++i) {
        m[i] = max(m[i], m[i-1]);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll p;
        cin >> p;
        cout << m[p] << endl;
    }
}
