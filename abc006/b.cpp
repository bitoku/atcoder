#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 10007;

int main() {
    ll n;
    cin >> n;
    vector<ll> memo(n);
    memo[0] = 0;
    memo[1] = 0;
    memo[2] = 1;
    for (int i = 3; i < n; ++i) {
        memo[i] = (memo[i-1] + memo[i-2] + memo[i-3]) % mod;
    }
    cout << memo[n-1] << endl;
}