#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

template< typename T >
void furui(T n, vector<T>& primes) {
    primes.push_back(2);
    primes.push_back(3);
    for (int i = 5; i < n; i += 2) {
        bool is_prime = true;
        for (auto p : primes) {
            if (i % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.push_back(i);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> primes;
    furui(55555, primes);
    vector<int> fprimes;
    for (int & prime : primes) {
        if (prime % 5 == 1) {
            fprimes.push_back(prime);
        }
    }
    cout << fprimes[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << fprimes[i];
    }
    cout << endl;
}
