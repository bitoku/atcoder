#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (ll)1e9 + 7;

vector<long long> fact, fact_inv, inv;

template< typename T >
void init_combi(size_t size, const T mod) {
    size += 1;
    fact.resize(size);
    fact_inv.resize(size);
    inv.resize(size);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 1; i < size-1; i++) {
        fact[i+1] = fact[i] * (i + 1) % mod;
        inv[i+1] = mod - inv[mod % (i+1)] * (mod / (i+1)) % mod;
        fact_inv[i+1] = fact_inv[i] * inv[i+1] % mod;
    }
}

template< typename T >
T mod_combi(T n, T k, T mod) {
    // return kCn % mod
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) % mod;
}

int main() {
    int X, Y;
    cin >> X >> Y;
    if ((X + Y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    // X = a + 2b
    // Y = 2a + b
    // A = a + b = (X + Y) / 3
    int A = (X + Y) / 3;
    // B = a - b = (Y - X)
    int B = Y - X;
    if ((A + B) % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll a = (A + B) / 2;
    if ((A - B) % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll b = (A - B) / 2;
    if (a < 0 || b < 0) {
        cout << 0 << endl;
        return 0;
    }
    init_combi((size_t)a+b, MOD);
    cout << mod_combi(a+b, a, MOD) << endl;
}
