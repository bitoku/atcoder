#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, Q;
    cin >> n >> Q;
    vector<ll> a(n);
    vector<ll> b(1);
    vector<int> idx(1);
    cin >> a[0];
    b[0] = a[0];
    idx[0] = 0;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        ll g = gcd(b.back(), a[i]);
        if (b.back() != g) {
            b.push_back(g);
            idx.push_back(i);
        }
    }
    for (int i = 0; i < Q; ++i) {
        ll q;
        cin >> q;
        for (int j = 0; j < b.size(); ++j) {
            q = gcd(q, b[j]);
            if (q == 1) {
                cout << idx[j] + 1 << endl;
                break;
            }
        }
        if (q > 1) {
            cout << q << endl;
        }
    }
}