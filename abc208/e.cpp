#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

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

int main() {
    ll n, k;
    cin >> n >> k;
    ll t = n;
    ll digit = 0;
    while (t > 0) {
        t /= 10;
        digit++;
    }
    vector<vector<map<ll, ll>>> dp(2, vector<map<ll, ll>>(digit + 1));
    vector<vector<ll>> zero(2, vector<ll>(digit+1));
    dp[0][0][k] = 1;
    for (int i = 1; i <= digit; i++) {
        int d = n / mod_pow(10ll, i-1ll, LONG_LONG_MAX) % 10;

        zero[0][i] += d * (zero[0][i-1] + zero[1][i-1]);
        zero[0][i] += zero[0][i-1];
        zero[1][i] += zero[1][i-1];
        zero[1][i] += (9 - d) * (zero[0][i-1] + zero[1][i-1]);
        zero[1][1] = 1;

        for (int j = 1; j < d; ++j) {
            for (auto [x, c]: dp[0][i-1]) {
                if (x >= j) dp[0][i][x / j] += c;
            }
            for (auto [x, c]: dp[1][i-1]) {
                if (x >= j) dp[0][i][x / j] += c;
            }
        }
        if (d > 0) {
            for (auto[x, c]: dp[0][i - 1]) {
                if (x >= d) dp[0][i][x / d] += c;
            }
            for (auto [x, c]: dp[1][i-1]) {
                if (x >= d) dp[1][i][x / d] += c;
            }
        }
        for (int j = d + 1; j < 10; ++j) {
            for (auto [x, c]: dp[0][i-1]) {
                if (x >= j) dp[1][i][x / j] += c;
            }
            for (auto [x, c]: dp[1][i-1]) {
                if (x >= j) dp[1][i][x / j] += c;
            }
        }
    }
    ll result = 0;
    for (int i = 1; i <= digit; ++i) {
        for (auto [x, c]: dp[0][i]) {
            result += c;
        }
    }
    for (int i = 1; i < digit; ++i) {
        for (auto [x, c]: dp[1][i]) {
            result += c;
        }
    }
    for (int i = 0; i <= digit; ++i) {
        result += zero[0][i];
    }
    cout << result << endl;
}