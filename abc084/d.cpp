#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

void generate_prime(vector<bool> &primes) {
    for (int i = 2; i < primes.size(); ++i) {
        primes[i] = true;
    }
    primes[2] = true;
    for (int i = 4; i < primes.size(); i += 2) {
        primes[i] = false;
    }
    for (int i = 3; i < primes.size(); i += 2) {
        if (!primes[i]) continue;
        for (int j = 2 * i; j < primes.size(); j += i) {
            primes[j] = false;
        }
    }
}

int main() {
    vector<bool> primes(100000);
    vector<int> like2017cnt(100000);
    int q;
    cin >> q;
    generate_prime(primes);
    like2017cnt[1] = 0;
    for (int i = 3; i < 100000; i += 2) {
        if (primes[i] && primes[(i + 1) / 2]) {
            like2017cnt[i] = 1;
        }
        like2017cnt[i] += like2017cnt[i - 2];
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        if (l == 1) {
            cout << like2017cnt[r] << endl;
        } else {
            cout << like2017cnt[r] - like2017cnt[l - 2] << endl;
        }
    }
}
