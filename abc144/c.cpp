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
    divisor(n, divisors);
    ll result = LONG_LONG_MAX;
    for (long long & div : divisors) {
        result = min(div - 1 + n / div - 1, result);
    }
    cout << result << endl;
}
