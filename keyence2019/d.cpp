#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    vector<vector<ll>> x(n, vector<ll>(m));
    vector<map<ll, ll>> vma(n);
    vector<map<ll, ll>> vmb(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x[i][j] = min(a[i], b[j]);
            vma[i][x[i][j]]++;
            vmb[j][x[i][j]]++;
        }
    }
    map<ll, int> ra;
    map<ll, int> rb;
    for (int i = 0; i < n; ++i) {
        if (ra.find(a[i]) != ra.end()) {
            cout << 0 << endl;
            return 0;
        }
        ra[a[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
        if (rb.find(b[i]) != rb.end()) {
            cout << 0 << endl;
            return 0;
        }
        rb[b[i]] = i;
    }
    ll result = 1;
    ll vacant = 0;
    for (ll i = n * m; i >= 1; --i) {
        if (ra.find(i) != ra.end() && rb.find(i) != rb.end()) {
            vacant += vma[ra[i]][i] - 1;
            vacant += vmb[rb[i]][i] - 1;
        }
        else if (ra.find(i) != ra.end()) {
            result *= vma[ra[i]][i];
            vacant += vma[ra[i]][i]-1;
        }
        else if (rb.find(i) != rb.end()) {
            result *= vmb[rb[i]][i];
            vacant += vmb[rb[i]][i]-1;
        } else {
            result *= vacant;
            vacant--;
        }
        result %= mod;
    }
    cout << result << endl;
}