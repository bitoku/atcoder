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
    vector<ll> a(n), b(n);
    multiset<ll> ma, mb;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += i;
        ma.insert(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i] += i;
        mb.insert(b[i]);
    }
    if (ma != mb) {
        cout << -1 << endl;
        return 0;
    }
    map<ll, deque<int>> m;
    for (int i = 0; i < n; ++i) {
        m[b[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        ll t = m[a[i]].front(); m[a[i]].pop_front();
        a[i] = t;
    }
    FenwickTree fw(n);
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        result += fw.sum(n - 1) - fw.sum(a[i]);
        fw.add(a[i], 1);
    }
    cout << result << endl;
}