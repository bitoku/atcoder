#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// TODO: solve without editorial

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
    ll n, q;
    cin >> n >> q;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        c[i]--;
    }
    vector<int> good(n, -1);
    deque<tuple<ll, ll, int>> query(q);
    for (int i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        query[i] = make_tuple(r, l, i);
    }
    sort(query.begin(), query.end());
    FenwickTree ft(n);
    vector<ll> ans(q);
    for (int i = 0; i < n; ++i) {
        ft.add(good[c[i]], -1);
        good[c[i]] = i;
        ft.add(i, 1);
        while (!query.empty() && get<0>(query.front()) == i) {
            ans[get<2>(query.front())] = ft.sum(i) - ft.sum(get<1>(query.front()) - 1);
            query.pop_front();
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
}
