#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

template< typename T >
void divisor(T n, vector<T>& divisors) {
    T root_n = (T)sqrt(n);
    for (int i = 1; i <= root_n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (n / i != i) divisors.push_back(n / i);
        }
    }
}

int main() {
    ll A, B;
    cin >> A >> B;
    vector<ll> divisors;
    divisor(gcd(A, B), divisors);
    vector<ll> primes;
    sort(divisors.begin(), divisors.end());
    for (const auto & item : divisors) {
        bool prime = true;
        // 1は後回し
        if (item == 1) continue;
        for (const auto & prime1 : primes) {
            if (item % p == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            primes.push_back(item);
        }
    }
    cout << primes.size() + 1 << endl;
}
