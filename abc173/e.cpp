#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> plus;
    vector<ll> minus;
    ll zero = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (a > 0) plus.push_back(a);
        else if (a < 0) minus.push_back(a);
        else zero++;
    }
    if (k == n) {
        if (zero > 0) {
            cout << 0 << endl;
            return 0;
        }
        ll result = 1;
        for (ll a: plus) {
            result *= a;
            result %= mod;
        }
        for (ll a: minus) {
            result *= a;
            result %= mod;
        }
        cout << (result + mod) % mod << endl;
        return 0;
    }
    if (k > n - zero || (k == n - zero && minus.size() % 2 == 1)) {
        cout << 0 << endl;
        return 0;
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end(), greater<>());
    if (plus.empty() && k % 2 == 1) {
        if (zero > 0) {
            cout << 0 << endl;
            return 0;
        }
        ll result = 1;
        for (int i = 0; i < k; ++i) {
            result *= minus[i];
            result %= mod;
        }
        cout << (result + mod) % mod  << endl;
        return 0;
    }
    ll result = 1;
    for (int i = 0; i < k; ++i) {
        if (minus.size() < 2 || i == k - 1) {
            result *= plus.back();
            result %= mod;
            plus.pop_back();
            continue;
        }
        if (plus.size() >= 2 && plus[plus.size() - 1] * plus[plus.size() - 2] >= minus[minus.size() - 1] * minus[minus.size() - 2]) {
            result *= plus.back() % mod;
            result %= mod;
            plus.pop_back();
        } else {
            result *= minus[minus.size() - 1] * minus[minus.size() - 2] % mod;
            result %= mod;
            minus.pop_back();
            minus.pop_back();
            i++;
        }
    }
    cout << result << endl;
}