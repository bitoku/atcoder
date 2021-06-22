#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 6/22

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i] + a[i];
    }
    vector<ll> xs;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n + 1; ++j) {
            xs.push_back(s[j] - s[i]);
            t = max(s[j] - s[i], t);
        }
    }
    ll len = 0;
    while (t > 0) {
        t >>= 1;
        len++;
    }
    ll result = 0;
    for (int i = len-1; i >= 0; --i) {
        vector<ll> nx;
        for (auto x: xs) {
            if (x & (1ll << i)) {
                nx.push_back(x);
            }
        }
        if (nx.size() >= k) {
            xs = nx;
            result |= (1ll << i);
        }
    }
    cout << result << endl;
}