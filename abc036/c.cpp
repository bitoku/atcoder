#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    map<ll, ll> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i]] = 0;
    }
    ll x = 0;
    for (auto& [k, v]: m) {
        v = x;
        x++;
    }
    for (int i = 0; i < n; ++i) {
        cout << m[a[i]] << endl;
    }
}