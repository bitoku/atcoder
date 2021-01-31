#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

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
    ll n;
    cin >> n;
    vector<ll> divisors;
    divisor(2 * n, divisors);
    ll cnt = 0;
    for (long long div : divisors) {
        if (div % 2 == 0 && 2*n / div % 2 == 1) {
            cnt++;
        } else if (div % 2 == 1 && 2*n / div % 2 == 0) {
            cnt++;
        }
    }
    cout << cnt << endl;
}
