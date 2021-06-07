#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> a(H, vector<ll>(W));
    vector<vector<ll>> b(H, vector<ll>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> b[i][j];
            a[i][j] = abs(a[i][j] - b[i][j]);
        }
    }
    vector<vector<bitset<15000>>> s(H, vector<bitset<15000>>(W));
    s[0][0][a[0][0]] = 1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 && j == 0) continue;
            if (i > 0) {
                s[i][j] |= s[i-1][j] << a[i][j];
                s[i][j] |= s[i-1][j] >> a[i][j];
                bitset<15000> bit;
                for (int k = 0; k <= a[i][j]; ++k) {
                    bit[a[i][j]-k] = s[i-1][j][k];
                }
                s[i][j] |= bit;
            }
            if (j > 0) {
                s[i][j] |= s[i][j-1] << a[i][j];
                s[i][j] |= s[i][j-1] >> a[i][j];
                bitset<15000> bit;
                for (int k = 0; k <= a[i][j]; ++k) {
                    bit[a[i][j]-k] = s[i][j-1][k];
                }
                s[i][j] |= bit;
            }
        }
    }
    for (int i = 0; i < 15000; ++i) {
        if (s[H-1][W-1][i]) {
            cout << i << endl;
            return 0;
        }
    }
}