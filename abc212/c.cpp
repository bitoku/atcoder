#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        ll temp = LONG_LONG_MAX;
        if (it != b.end()) {
            temp = min(temp, abs(a[i] - *it));
        }
        if (it != b.begin()) {
            temp = min(temp, abs(a[i] - *(--it)));
        }
        result = min(temp, result);
    }
    cout << result << endl;
}