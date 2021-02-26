#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int H, W;

ll dfs(const vector<vector<ll>>& a, vector<vector<ll>>& b, int h, int w) {
    if (b[h][w] > 0) return b[h][w];
    int dir[4][2] = {
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1},
    };
    ll result = 1;
    for (auto & d : dir) {
        ll ni = h + d[0];
        ll nj = w + d[1];
        if (ni < 0 || ni >= H || nj < 0 || nj >= W ) continue;
        if (a[ni][nj] <= a[h][w]) continue;
        result = (result + dfs(a, b, ni, nj)) % mod;
    }
    b[h][w] = result % mod;
    return result;
}

int main() {
    cin >> H >> W;
    vector<vector<ll>> a(H, vector<ll>(W));
    vector<vector<ll>> b(H, vector<ll>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
        }
    }
    ll result = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            result = (result + dfs(a, b, i, j)) % mod;
        }
    }
    cout << result << endl;
}
