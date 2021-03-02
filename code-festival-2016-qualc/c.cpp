#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> t(n);
    vector<ll> a(n);
    vector<pair<ll, ll>> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    h[0].first = t[0];
    h[0].second = t[0];
    for (int i = 1; i < n; ++i) {
        if (t[i] > t[i-1]) {
            h[i].first = t[i];
            h[i].second = t[i];
        } else {
            h[i].first = 1;
            h[i].second = t[i];
        }
    }
    h[n-1].first = max(h[n-1].first, a[n-1]);
    h[n-1].second = min(h[n-1].second, a[n-1]);
    for (int i = n-2; i >= 0; --i) {
        if (a[i] > a[i+1]) {
            h[i].first = max(h[i].first, a[i]);
            h[i].second = min(h[i].second, a[i]);
        } else {
            h[i].first = max(h[i].first, 1ll);
            h[i].second = min(h[i].second, a[i]);
        }
    }
    ll result = 1;
    for (int i = 0; i < n; ++i) {
        result *= max(h[i].second - h[i].first + 1, 0ll);
        result %= mod;
    }
    cout << result << endl;
}
