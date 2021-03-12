#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<>());
    auto func = [a, p, n, m, v](int x, int _) {
        if (x < p) return true;
        if (a[x] + m < a[p-1]) return false;
        ll ok = (p - 1 + n - x) * m;
        for (int i = p - 1; i < x; ++i) {
            ok += max(a[x] + m - a[i], 0ll);
        }
        if (ok < m * v) return false;
        return true;
    };
    vector<int> idx(a.size());
    iota(idx.begin(), idx.end(), 0);
    auto it = lower_bound(idx.begin(), idx.end(), 0, func);
    if (it == idx.end()) {
        cout << n << endl;
    } else {
        cout << *it << endl;
    }
}
