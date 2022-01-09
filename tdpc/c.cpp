#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int msb(int x) {
    for (int i = 0; i < 30; ++i) {
        if ((1 << i) > x) return i;
    }
}

ld elo(ld rp, ld rq) {
    return 1 / (1 + pow(10, (rq - rp) / 400));
}

int main() {
    int k;
    cin >> k;
    vector<vector<ld>> v((1 << (k+1)) + 1, vector<ld>(1 << k));
    for (int i = (1 << k); i < (1 << (k + 1)); ++i) {
        v[i][i-(1<<k)] = 1;
    }
    vector<ld> r(1 << k);
    for (int i = 0; i < (1 << k); ++i) {
        cin >> r[i];
    }
    for (int i = (1 << k) - 1; i >= 1; --i) {
        // v[i << 1] と v[(i << 1) + 1]
        int d = msb(i);
        int t = 1 << (k + 1 - d);
        int x = (i << (k + 1 - d)) - (1 << k);
        for (int j = x; j < x + (t >> 1); ++j) {
            for (int l = x + (t >> 1); l < x + t; ++l) {
                v[i][j] += v[(i << 1) + 1][l] * elo(r[j], r[l]);
            }
            v[i][j] *= v[i << 1][j];
        }
        for (int j = x + (t >> 1); j < x + t; ++j) {
            for (int l = x; l < (x + (t >> 1)); ++l) {
                v[i][j] += v[i << 1][l] * elo(r[j], r[l]);
            }
            v[i][j] *= v[(i << 1) + 1][j];
        }
    }
    for (int i = 0; i < (1 << k); ++i) {
        cout << setprecision(16) << v[1][i] << endl;
    }
}