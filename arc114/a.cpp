#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template< typename T >
void get_primes(T n, vector<T>& primes) {
    primes.push_back(2);
    primes.push_back(3);
    for (int i = 5; i < n; i += 2) {
        bool is_prime = true;
        for (auto p : primes) {
            if (p * p > i) break;
            if (i % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.push_back(i);
    }
}

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    vector<ll> primes;
    get_primes(50ll, primes);
    ll n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    ll result = LONG_LONG_MAX;
    for (int i = 1; i < (1 << 15); ++i) {
        ll temp = 1;
        for (int j = 0; j < 15; ++j) {
            if (i & (1 << j)) temp *= primes[j];
        }
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (gcd(x[j], temp) == 1) ok = false;
        }
        if (ok) {
            result = min(result, temp);
        }
    }
    cout << result << endl;
}
