#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 06/28

unordered_map<ll, ll> memo;
ll a, b, c, d;

ll dfs(ll n) {
    if (memo.find(n) != memo.end()) return memo[n];
    if (n == 2) return min(a, d) + d;
    if (n == 1) return d;
    if (n == 0) return 0;
    ll result = LONG_LONG_MAX;
    if (LONG_LONG_MAX / d >= n) {
        result = n * d;
    }
    ll k;
    k = 2;
    result = min(result, dfs(n / k) + d * (n - n / k * k) + a);
    result = min(result, dfs(n / k + 1) + d * (n / k * k + k - n) + a);
    k = 3;
    result = min(result, dfs(n / k) + d * (n - n / k * k) + b);
    result = min(result, dfs(n / k + 1) + d * (n / k * k + k - n) + b);
    k = 5;
    result = min(result, dfs(n / k) + d * (n - n / k * k) + c);
    result = min(result, dfs(n / k + 1) + d * (n / k * k + k - n) + c);
    memo[n] = result;
    return result;
}

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n;
        cin >> n >> a >> b >> c >> d;
        cout << dfs(n) << endl;
        memo.clear();
    }
}