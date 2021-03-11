#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

template< typename T >
T mod_pow(T x, T n, const T &p) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

vector<long long> fact, fact_inv, inv;

template< typename T >
void init_combi(size_t size, const T mod) {
    size += 1;
    fact.resize(size);
    fact_inv.resize(size);
    inv.resize(size);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 1; i < size-1; i++) {
        fact[i+1] = fact[i] * (i + 1) % mod;
        inv[i+1] = mod - inv[mod % (i+1)] * (mod / (i+1)) % mod;
        fact_inv[i+1] = fact_inv[i] * inv[i+1] % mod;
    }
}

int main() {
    ll H, W, K;
    cin >> H >> W >> K;
    vector<string> s(H+1, string(W+1, '.'));
    vector<vector<ll>> v(H+2, vector<ll>(W+2));
    for (int i = 0; i < K; ++i) {
        int h, w;
        char c;
        cin >> h >> w >> c;
        s[h][w] = c;
    }
    init_combi(3, mod);
    v[1][1] = 1;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (s[i][j] == 'R') {
                v[i][j+1] += v[i][j];
                v[i][j+1] %= mod;
            }
            if (s[i][j] == 'D') {
                v[i+1][j] += v[i][j];
                v[i+1][j] %= mod;
            }
            if (s[i][j] == 'X') {
                v[i][j+1] += v[i][j];
                v[i+1][j] += v[i][j];
                v[i][j+1] %= mod;
                v[i+1][j] %= mod;
            }
            if (s[i][j] == '.') {
                v[i][j+1] += v[i][j] * 2 * inv[3];
                v[i+1][j] += v[i][j] * 2 * inv[3];
                v[i][j+1] %= mod;
                v[i+1][j] %= mod;
            }
        }
    }
    cout << v[H][W] * mod_pow(3ll, H * W - K, mod) % mod << endl;
}
