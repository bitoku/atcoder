#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

class BIT {
public:
    unsigned long n;
    vector<ll> a;
    BIT(unsigned long _n): n(_n), a(n+1, 0) {}

    void operate(unsigned long i, ll x) {
        i++;
        for (ll k = i; k <= n; k += (k & -k)) a[k] ^= x;
    }

    ll range_query(unsigned long i, unsigned long j) {
        return query(j) ^ query(i);
    }

    ll query(unsigned long i) {
        if (i == -1) return 0;
        i++;
        ll ret = 0;
        for (ll k = i; k > 0; k -= (k & -k)) ret ^= a[k];
        return ret;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    BIT bit(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        bit.operate(i, a[i]);
    }
    for (int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            bit.operate(--x, y);
        } else {
            cout << bit.range_query(x - 2, --y) << endl;
        }
    }
}
