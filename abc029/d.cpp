#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

void solve(ll n) {
    ll result = 0;
    for (ll i = 1; i <= n; i *= 10) {
        result += (n / (i * 10)) * i;
        ll m = min(max(n % (i * 10) - i + 1, 0ll), i);
        result += m;
    }
    cout << result << endl;
}

int main() {
    ll n;
    cin >> n;
    solve(n);
}
