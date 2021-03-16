#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

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
    ll a, b, x;
    cin >> a >> b >> x;
    auto func = [a, b, x](ll n) {
        ll t = n;
        ll d = 0;
        while (t > 0) {
            t /= 10;
            d++;
        }
        if (x >= a * n + b * d) return true;
        else return false;
    };
    cout << binsearch(1000000001, 0, func) << endl;
}
