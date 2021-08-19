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
    ll k;
    cin >> k;
    set<ll> div = divisor(k);
    ll result = 0;
    for (auto x: div) {
        for (auto y: div) {
            if (y > min(x, k/x)) break;
            if (k % (x * y) == 0 && k <= x * y * y) {
                result++;
            }
        }
    }
    cout << result << endl;
}