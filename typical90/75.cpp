#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

map<ll, ll> factorize(ll n) {
    map<ll, ll> ret;
    while (n % 2 == 0) {
        n /= 2;
        ret[2]++;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            n /= i;
            ret[i]++;
        }
    }
    if (n > 1) ret[n]++;
    return ret;
}

int main() {
    ll n;
    cin >> n;
    map<ll, ll> fact = factorize(n);
    ll temp = 0;
    for (auto [x, y]: fact) {
        temp += y;
    }
    temp--;
    ll result = 0;
    while (temp > 0) {
        temp >>= 1;
        result++;
    }
    cout << result << endl;
}