#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = (ll)1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;
    ll ans = 0;
    for (ll k = K; k <= N + 1; ++k) {
        ll min_sum = (k - 1) * k / 2;
        ll max_sum = (N + N - k + 1) * k / 2;
        ans = (ans + max_sum - min_sum + 1) % MOD;
    }
    cout << ans << endl;
}
