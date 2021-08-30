#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 08/30

template<class Condition>
ll binsearch(ll ng, ll ok, Condition func) {
    while (abs(ok - ng) > 1) {
        ll mid = (ng + ok) / 2;
        if (func(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ll n;
    cin >> n;
    auto func = [&](ll x) {
        return x * x + x <= 2 * n + 2;
    };
    ll k = binsearch(3000000000, 1, func);
    cout << n + 1 - k << endl;
}