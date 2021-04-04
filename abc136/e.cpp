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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> divisors;
    divisor(sum, divisors);
    sort(divisors.begin(), divisors.end(), greater<>());
    for (const auto div: divisors) {
        vector<ll> r(n);
        for (int i = 0; i < n; ++i) {
            r[i] = a[i] % div;
        }
        sort(r.begin(), r.end());
        vector<ll> s(n+1);
        for (int i = 0; i < n; ++i) {
            s[i+1] = s[i] + r[i];
        }
        for (int i = 0; i <= n; ++i) {
            if (s[i] == div * (n - i) - (s[n] - s[i]) && s[i] <= k) {
                cout << div << endl;
                return 0;
            }
        }
    }
}
