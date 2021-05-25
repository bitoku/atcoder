#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n+1);
    for (int i = 0; i < n; ++i) {
        b[i+1] = b[i];
        if (i % 2 == 0) b[i+1] += a[i];
        else b[i+1] -= a[i];
    }
    map<ll, ll> m;
    for (int i = 0; i <= n; ++i) {
        m[b[i]]++;
    }
    ll result = 0;
    for (auto [k, v]: m) {
        result += v * (v - 1) / 2;
    }
    cout << result << endl;
}