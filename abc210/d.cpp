#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 07/21

int main() {
    ll H, W, C;
    cin >> H >> W >> C;
    vector<vector<ll>> a(H, vector<ll>(W));
    vector<vector<ll>> x(H, vector<ll>(W));
    vector<vector<ll>> y(H, vector<ll>(W));
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            x[i][j] = a[i][j] + C*i + C*j;
            y[i][j] = a[i][j] - C*i - C*j;
        }
    }
    for (int j = 0; j < W; ++j) {
        for (int i = 1; i < H; ++i) {
            y[i][j] = min(y[i-1][j], y[i][j]);
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 1; j < W; ++j) {
            y[i][j] = min(y[i][j-1], y[i][j]);
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                result = min(result, x[i][j] + y[i][j-1]);
            } else if (j == 0) {
                result = min(result, x[i][j] + y[i-1][j]);
            } else {
                result = min(result, x[i][j] + min(y[i][j-1], y[i-1][j]));
            }
        }
    }
    for (int i = 0; i < H; ++i) {
        reverse(a[i].begin(), a[i].end());
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            x[i][j] = a[i][j] + C*i + C*j;
            y[i][j] = a[i][j] - C*i - C*j;
        }
    }
    for (int j = 0; j < W; ++j) {
        for (int i = 1; i < H; ++i) {
            y[i][j] = min(y[i-1][j], y[i][j]);
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 1; j < W; ++j) {
            y[i][j] = min(y[i][j-1], y[i][j]);
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                result = min(result, x[i][j] + y[i][j-1]);
            } else if (j == 0) {
                result = min(result, x[i][j] + y[i-1][j]);
            } else {
                result = min(result, x[i][j] + min(y[i][j-1], y[i-1][j]));
            }
        }
    }
    cout << result << endl;
}