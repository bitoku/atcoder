#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

ll dp[100001][4];

int main() {
    string s;
    cin >> s;
    dp[s.size()][0] = 0;
    dp[s.size()][1] = 0;
    dp[s.size()][2] = 0;
    dp[s.size()][3] = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '?') {
            dp[i][3] = (3 * dp[i+1][3]) % mod;
            dp[i][2] = (3 * dp[i+1][2] + dp[i+1][3]) % mod;
            dp[i][1] = (3 * dp[i+1][1] + dp[i+1][2]) % mod;
            dp[i][0] = (3 * dp[i+1][0] + dp[i+1][1]) % mod;
        } else {
            dp[i][3] = dp[i+1][3];
            if (s[i] == 'C') dp[i][2] = (dp[i+1][2] + dp[i+1][3]) % mod;
            else dp[i][2] = dp[i+1][2];
            if (s[i] == 'B') dp[i][1] = (dp[i+1][1] + dp[i+1][2]) % mod;
            else dp[i][1] = dp[i+1][1];
            if (s[i] == 'A') dp[i][0] = (dp[i+1][0] + dp[i+1][1]) % mod;
            else dp[i][0] = dp[i+1][0];
        }
    }
    cout << dp[0][0] << endl;
}

//template< typename T >
//T mod_pow(T x, T n, const T &p) {
//    T ret = 1;
//    while(n > 0) {
//        if(n & 1) (ret *= x) %= p;
//        (x *= x) %= p;
//        n >>= 1;
//    }
//    return ret;
//}

//int main() {
//    string s;
//    cin >> s;
//    vector<int> a, b, c, z;
//    for (int i = 0; i < s.size(); ++i) {
//        if (s[i] == 'A') a.push_back(i);
//        if (s[i] == 'B') b.push_back(i);
//        if (s[i] == 'C') c.push_back(i);
//        if (s[i] == '?') z.push_back(i);
//    }
//    vector<ll> bc, zc, bz, zz;
//    for (int i = 0; i < b.size(); ++i) {
//        auto it = upper_bound(c.begin(), c.end(), b[i]);
//        ll x = distance(c.begin(), it);
//        bc.push_back(c.size() - x);
//    }
//    for (int i = 0; i < b.size(); ++i) {
//        auto it = upper_bound(z.begin(), z.end(), b[i]);
//        ll x = distance(z.begin(), it);
//        bz.push_back(z.size() - x);
//    }
//    for (int i = 0; i < z.size(); ++i) {
//        auto it = upper_bound(c.begin(), c.end(), z[i]);
//        ll x = distance(c.begin(), it);
//        zc.push_back(c.size() - x);
//    }
//    for (int i = 0; i < z.size(); ++i) {
//        auto it = upper_bound(z.begin(), z.end(), z[i]);
//        ll x = distance(z.begin(), it);
//        zz.push_back(z.size() - x);
//    }
//    for (int i = bc.size() - 1; i >= 1; --i) {
//        bc[i-1] = (bc[i-1] + bc[i]) % mod;
//    }
//    for (int i = bz.size() - 1; i >= 1; --i) {
//        bz[i-1] = (bz[i-1] + bz[i]) % mod;
//    }
//    for (int i = zc.size() - 1; i >= 1; --i) {
//        zc[i-1] = (zc[i-1] + zc[i]) % mod;
//    }
//    for (int i = zz.size() - 1; i >= 1; --i) {
//        zz[i-1] = (zz[i-1] + zz[i]) % mod;
//    }
//    ll result = 0;
//    if (!b.empty()) {
//        for (int i = 0; i < a.size(); ++i) {
//            auto it = upper_bound(b.begin(), b.end(), a[i]);
//            if (it == b.end()) continue;
//            ll x = distance(b.begin(), it);
//            result = (result + (bc[x] * mod_pow(3ll, (ll) z.size(), mod) % mod)) % mod;
//            result = (result + (bz[x] * mod_pow(3ll, (ll) z.size() - 1, mod) % mod)) % mod;
//        }
//        for (int i = 0; i < z.size(); ++i) {
//            auto it = upper_bound(b.begin(), b.end(), z[i]);
//            if (it == b.end()) continue;
//            ll x = distance(b.begin(), it);
//            result = (result + (bc[x] * mod_pow(3ll, (ll)z.size() - 1, mod) % mod)) % mod;
//            result = (result + (bz[x] * mod_pow(3ll, (ll)z.size() - 2, mod) % mod)) % mod;
//        }
//    }
//    if (!z.empty()) {
//        for (int i = 0; i < a.size(); ++i) {
//            auto it = upper_bound(z.begin(), z.end(), a[i]);
//            if (it == z.end()) continue;
//            ll x = distance(z.begin(), it);
//            result = (result + (zc[x] * mod_pow(3ll, (ll) z.size() - 1, mod) % mod)) % mod;
//            result = (result + (zz[x] * mod_pow(3ll, (ll) z.size() - 2, mod) % mod)) % mod;
//        }
//        for (int i = 0; i < z.size(); ++i) {
//            auto it = upper_bound(z.begin(), z.end(), z[i]);
//            if (it == z.end()) continue;
//            ll x = distance(z.begin(), it);
//            result = (result + (zc[x] * mod_pow(3ll, (ll) z.size() - 2, mod) % mod)) % mod;
//            result = (result + (zz[x] * mod_pow(3ll, (ll) z.size() - 3, mod) % mod)) % mod;
//        }
//    }
//    cout << result << endl;
//}
