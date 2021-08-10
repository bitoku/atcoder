#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k, p;
    cin >> n >> k >> p;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll lim = min(20ll, n);
    ll result = 0;
    for (ll i = 0; i <= min(lim, k); ++i) {
        if (k - i > n - lim) continue;
        vector<int> idx(lim, 1);
        for (int j = 0; j < lim - i; ++j) {
            idx[j] = 0;
        }
        vector<ll> b;
        do {
            ll temp = 0;
            for (int j = 0; j < lim; ++j) {
                if (idx[j]) temp += a[j];
            }
            b.push_back(temp);
        } while(next_permutation(idx.begin(), idx.end()));
        idx.clear();
        idx.resize(n - lim, 1);
        for (int j = 0; j < n - lim - k + i; ++j) {
            idx[j] = 0;
        }
        vector<ll> c;
        do {
            ll temp = 0;
            for (int j = 0; j < n - lim; ++j) {
                if (idx[j]) temp += a[20 + j];
            }
            c.push_back(temp);
        } while(next_permutation(idx.begin(), idx.end()));
        sort(c.begin(), c.end());
        for (auto x: b) {
            auto it = upper_bound(c.begin(), c.end(), p - x);
            result += distance(c.begin(), it);
        }
    }
    cout << result << endl;
}