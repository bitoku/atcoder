#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

set<ll> divisor(ll n) {
    set<ll> ret;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.insert(i);
            ret.insert(n / i);
        }
    }
    return ret;
}

int main() {
    // N = k^x (yk + 1)
    ll n;
    cin >> n;
    ll result = 0;
    // x == 0
    set<ll> k = divisor(n - 1);
    k.erase(1);
    set<ll> d = divisor(n);
    for (auto i: d) {
        if (i == 1) continue;
        ll temp = n;
        while (temp % i == 0) temp /= i;
        if (temp % i == 1) result++;
    }
    cout << k.size() + result << endl;
}