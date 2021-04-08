#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
    ll s, p;
    cin >> s >> p;
    vector<ll> divisors;
    divisor(p, divisors);
    ll cnt = 0;
    for (const auto n: divisors) {
        ll m = p / n;
        if (n + m == s) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
