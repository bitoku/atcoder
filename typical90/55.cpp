#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, p, q;
    cin >> n >> p >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> idx(n);
    for (int i = 1; i <= 5; ++i) {
        idx[n-i] = 1;
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        ll ti = a[i];
        for (int j = i+1; j < n; ++j) {
            ll tj = ti * a[j] % p;
            for (int k = j+1; k < n; ++k) {
                ll tk = tj * a[k] % p;
                for (int l = k+1; l < n; ++l) {
                    ll tl = tk * a[l] % p;
                    for (int m = l+1; m < n; ++m) {
                        if (tl * a[m] % p == q) {
                            result++;
                        }
                    }
                }
            }
        }
    }
    cout << result << endl;
}