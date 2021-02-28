#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;
        ll a = gcd(x + y, p + q);
        ll lim = (x + y) / a * (p + q);
        bool ok = false;
        ll K = (2 * x + 2 * y);
        ll cnt = 0;
        ll dleft = 0;
        ll dright = 0;
        for (ll t = p; t < lim; t += p + q) {
            if (t < x) continue;
            ll n = (t - x) / K;
            ll left = t - (K * n + x + y);
            ll right = K * (n + 1) + x - (t + q);
            t += p + q;
            ll m = (t - x) / K;
            ll nleft = t - (K * n + x + y);
            ll nright = K * (n + 1) + x - (t + q);
            dleft = nleft - left;
            dright = nright - right;
        }
        for (ll t = p; t < lim; t += p + q) {
            cnt++;
            if (t < x) continue;
            ll n = (t - x) / K;
            if (t < K * n + x + y) {
                cout << t << endl;
                ok = true;
                cout << cnt << endl;
                break;
            }
            if (K * (n + 1) + x < t + q) {
                cout << K * n + x + y << endl;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "infinity" << endl;
        }
    }
}
