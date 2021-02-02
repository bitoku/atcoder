#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        ll diff = a[i] + a[i+1] - x;
        if (diff > 0) {
            ll minus = min(diff, a[i+1]);
            a[i+1] -= minus;
            if (minus == a[i+1]) {
                a[i] -= diff - minus;
            }
            cnt += diff;
        }
    }
    cout << cnt << endl;
}
