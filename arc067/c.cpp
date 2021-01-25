#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

void factorize(int n, map<int, int>& m) {
    int root_n = (int)sqrt(n);
    while ((n & 1) == 0) {
        n >>= 1;
        m[2]++;
    }
    for (int i = 3; i <= root_n; i += 2) {
        while (n % i == 0) {
            n /= i;
            m[i]++;
        }
    }
    if (n > 1) {
        m[n]++;
    }
}
int main() {
    int n;
    cin >> n;
    map<int, int> factor_all;
    for (int i = 1; i <= n; ++i) {
        map<int, int> factor;
        factorize(i, factor);
        for (auto pfactor : factor) {
            int p = pfactor.first;
            int cnt = pfactor.second;
            factor_all[p] += cnt;
        }
    }
    ll result = 1;
    for (auto pfactor : factor_all) {
        result = (result * (pfactor.second + 1)) % mod;
    }
    cout << result << endl;
}
