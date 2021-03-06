#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();
    ll dp[200001][1 << 16][2] = {};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            dp[i+1][j][0] = (dp[i][j][0] * j + dp[i][j-1][0] * (16 - j)) % mod;
        }
    }

}
