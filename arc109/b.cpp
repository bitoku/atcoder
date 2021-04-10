#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

template<class Condition>
ll binsearch(ll ng, ll ok, Condition func) {
    // ngは常に条件を満たさない, okは常に条件を満たす
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
    auto func = [n](ll k) {
        return k * (k + 1) / 2 <= n + 1;
    };
    ll k = binsearch(INT_MAX - 1, 0, func);
    cout << n - k + 1 << endl;
}
