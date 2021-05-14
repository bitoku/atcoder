#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

class FenwickTree {
public:
    ll n;
    vector<ll> a;
    explicit FenwickTree(ll _n): n(_n), a(_n+1, 0) {}

    void add(ll i, ll x) {
        i++;
        if (i == 0) return;
        for (ll k = i; k <= n; k+=(k & -k)) {
            a[k] += x;
        }
    }

    ll sum(ll i) {
        i++;
        ll s = 0;
        if (i == 0) return s;
        for (ll k = i; k > 0; k -= (k & -k)) {
            s += a[k];
        }
        return s;
    }
};


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll result = 0;
    FenwickTree ft(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ft.add(a[i]-1, 1);
        result += ft.sum(n-1) - ft.sum(a[i]-1);
    }
    cout << result << endl;
}