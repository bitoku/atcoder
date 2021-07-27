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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    set<pair<ll, ll>> mp;
    mp.insert(make_pair(a[0], b[0]));
    for (int i = 1; i < n; ++i) {
        set<pair<ll, ll>> nmp;
        for (auto [x, y]: mp) {
            nmp.insert(make_pair(gcd(x, a[i]), gcd(y, b[i])));
            nmp.insert(make_pair(gcd(x, b[i]), gcd(y, a[i])));
        }
        mp = nmp;
    }
    ll result = 0;
    for (auto [x, y]: mp) {
        result = max(result, x * y / gcd(x, y));
    }
    cout << result << endl;
}