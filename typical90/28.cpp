#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> f(1001, vector<int>(1001));
    for (int i = 0; i < n; ++i) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        f[ly][lx]++;
        f[ly][rx]--;
        f[ry][lx]--;
        f[ry][rx]++;
    }
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            f[i][j] += f[i][j-1];
        }
    }
    for (int j = 0; j <= 1000; ++j) {
        for (int i = 1; i <= 1000; ++i) {
            f[i][j] += f[i-1][j];
        }
    }
    vector<ll> overlap(n+1);
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= 1000; ++j) {
            overlap[f[i][j]]++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << overlap[i] << endl;
    }
}