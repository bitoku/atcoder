#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    ll ans = 0;
    for (ll x = 1; x <= N; ++x) {
        ll y = N / x;
        ans += x * (1 + y) * y / 2;
    }
    cout << ans << endl;
}

