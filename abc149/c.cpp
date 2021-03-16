#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

template< typename T >
T solve(T n, vector<T>& primes) {
    if (n <= 2) {
        return 2;
    }
    primes.push_back(2);
    for (int i = 3; true; i += 2) {
        bool is_prime = true;
        for (auto p : primes) {
            if (p * p > i) break;
            if (i % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(i);
            if (i >= n) return i;
        }
    }
}

int main() {
    ll x;
    cin >> x;
    vector<ll> primes;
    cout << solve(x, primes) << endl;
}
