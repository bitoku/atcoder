#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    sort(divisors.begin(), divisors.end());
    for (const auto e: divisors) {
        cout << e << endl;
    }

}
