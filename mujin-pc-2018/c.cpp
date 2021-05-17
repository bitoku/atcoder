#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        ll l = -1;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                l++;
            } else {
                for (int k = 0; k <= l; ++k) {
                    a[i][j-k-1] = l;
                }
                l = -1;
            }
        }
        if (l > 0) {
            for (int k = 0; k <= l; ++k) {
                a[i][m-k-1] = l;
            }
        }
    }
    ll result = 0;
    for (int j = 0; j < m; ++j) {
        ll l = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i][j] == '.') {
                l++;
            } else {
                for (int k = 0; k <= l; ++k) {
                    result += a[i-k-1][j] * l;
                }
                l = -1;
            }
        }
        if (l > 0) {
            for (int k = 0; k <= l; ++k) {
                result += a[n-k-1][j] * l;
            }
        }
    }
    cout << result << endl;
}