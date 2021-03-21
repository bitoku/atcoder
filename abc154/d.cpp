#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

double solve(ll n, ll k, vector<ll>& p) {
    ll t = 0;
    for (int i = 0; i < k; ++i) {
        t += p[i];
    }
    ll s = t;
    for (int i = k; i < n; ++i) {
        t -= p[i-k];
        t += p[i];
        s = max(s, t);
    }
    return (k + s) / 2.0;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    cout << setprecision(15) << solve(n, k, p) << endl;
}
