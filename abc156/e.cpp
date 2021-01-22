#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int fact[200001] = {0};

ll mpow(ll x, int n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ans;
}

ll combi(int n, int r){
    ll ans = (fact[n] * mpow(fact[n-r], MOD-2)) % MOD;
    ans = ans * mpow(fact[r], MOD-2) % MOD;
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    fact[0] = 1;
    for (ll i = 1; i <= 200000;i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    ll l = min(k, n - 1);
    ll ans = 0;
    for(int i = 1; i <= l; ++i){
        ans += ((combi(n - 1, i) * combi(n, i))) % MOD;
    }
    cout << (ans+1) % MOD << endl;
}
