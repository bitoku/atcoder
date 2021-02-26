#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll m = 0;
    vector<ll> max_a(n);
    for (int i = n-1; i >= 0; --i) {
        m = max(m, a[i]);
        max_a[i] = m;
    }
    ll diff_max = 0;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        ll diff = max_a[i] - a[i];
        if (diff > diff_max) {
            diff_max = diff;
            cnt = 1;
        } else if (diff == diff_max) {
            cnt++;
        }
    }
    cout << cnt << endl;
}
