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
    FenwickTree(): n(0) {}

    void init(ll _n) {
        n = _n;
        a.clear();
        a.resize(n+1, 0);
    }

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
    string s;
    cin >> s;
    ll q;
    cin >> q;
    FenwickTree ft[26];
    for (int i = 0; i < 26; ++i) {
        ft[i].init(n);
    }
    for (int i = 0; i < n; ++i) {
        ft[s[i]-'a'].add(i, 1);
    }
    for (int i = 0; i < q; ++i) {
        int qt;
        cin >> qt;
        if (qt == 1) {
            int j;
            char c;
            cin >> j >> c;
            j--;
            ft[s[j]-'a'].add(j, -1);
            ft[c-'a'].add(j, 1);
            s[j] = c;
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            ll result = 0;
            for (int j = 0; j < 26; ++j) {
                if (ft[j].sum(r) - ft[j].sum(l-1) > 0) {
                    result++;
                }
            }
            cout << result << endl;
        }
    }
}