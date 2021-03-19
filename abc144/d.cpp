#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ld eps = 1e-9;

template<class Condition>
ld binsearch(ld ng, ld ok, Condition func) {
    // ngは常に条件を満たさない, okは常に条件を満たす
    while (abs(ok - ng) > eps) {
        ld mid = (ng + ok) / 2.0;
        if (func(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    auto func = [a, b, x](ld theta) {
        if (theta > M_PI / 2 - eps) return true;
        ld t = tan(theta);
        if (b < a * t) {
            return x > a * b * b / t / 2.0;
        } else {
            return x > a * a * b - a * a * a * t / 2.0;
        }
    };
    cout << setprecision(15) << binsearch(0, M_PI / 2, func) * 180 / M_PI << endl;
}
