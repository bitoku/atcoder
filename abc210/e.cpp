#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    ll result = 0;
    for (int i = 0; i < m; ++i) {
        auto [c, p] = v[i];
        ll g = gcd(n, p);
        if (g == 1) {
            cout << result + (n - 1) * c << endl;
            return 0;
        }
        result += (n / g - 1) * g * c;
        n = g;
    }
    cout << -1 << endl;
}