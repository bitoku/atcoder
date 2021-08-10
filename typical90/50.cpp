#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, l;
    cin >> n >> l;
    vector<ll> stair(n+1);
    stair[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (i + l <= n) stair[i + l] = (stair[i + l] + stair[i]) % mod;
        stair[i + 1] = (stair[i + 1] + stair[i]) % mod;
    }
    cout << stair[n] << endl;
}