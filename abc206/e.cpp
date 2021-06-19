#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll eulerPhi(ll n) {
    if (n == 0) return 0;
    ll result = n;
    for (ll x = 2; x * x <= n; ++x) {
        if (n % x == 0) {
            result -= result / x;
            while (n % x == 0) n /= x;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

int main() {
    ll l, r;
    cin >> l >> r;
    cout << eulerPhi(1) << endl;
    vector<ll> euler(r / 2 + 1);
    for (int i = 2; i <= r / 2; ++i) {
        euler[i] = eulerPhi(i);
    }
    for (int i = 1; i <= r / 2; ++i) {
        euler[i] += euler[i-1];
    }
    for (int i = 1; i <= r / 2; ++i) {
        euler[i] *= 2;
    }
    for (int i = 2; i < r; ++i) {
        ll sup = r / i;

    }
}