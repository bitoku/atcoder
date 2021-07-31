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
    ll p;
    cin >> p;
    if ( p == 2 ) {
        cout << 2 << endl;
        return 0;
    }
    set<ll> div1 = divisor(p + 1);
    set<ll> div2 = divisor(p - 1);

}