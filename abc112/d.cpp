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
    int n, m;
    cin >> n >> m;
    vector<int> divisors;
    divisor(m, divisors);
    sort(divisors.begin(), divisors.end(), greater<>{});
    for (int divisor : divisors) {
        if (n > m / divisor) continue;
        cout << divisor << endl;
        break;
    }
}
