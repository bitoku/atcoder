#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 06/29

ll msb(ll a) {
    return a & (-a);
}

bool base(vector<ll>& out, vector<ll>& bases, ll add) {
    for (auto b: bases) {
        if (msb(b) & add) {
            add ^= b;
        }
    }
    out = bases;
    if (add == 0) return false;
    out.push_back(add);
    return true;
}

bool generatable(vector<ll>& bases, ll add) {
    for (auto b: bases) {
        if (msb(b) & add) add ^= b;
    }
    return add == 0;
}

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        string s;
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        cin >> s;
        vector<vector<ll>> dp(n + 1);
        int win = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (s[j] == '0') {
                base(dp[j], dp[j+1], a[j]);
            } else {
                if (generatable(dp[j+1], a[j])) {
                    dp[j] = dp[j+1];
                } else {
                    win = 1;
                }
            }
        }
        cout << win << endl;
    }
}