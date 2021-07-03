#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k, m, r;
    cin >> n >> k >> m >> r;
    vector<ll> s(n-1);
    for (int i = 0; i < n-1; ++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), greater<>());
    ll sum = 0;
    ll target = r * k;
    for (int i = 0; i < k - 1; ++i) {
        sum += s[i];
    }
    if (n > k && sum + s[k - 1] >= target) {
        cout << 0 << endl;
        return 0;
    }
    if (target - sum > m) {
        cout << -1 << endl;
        return 0;
    } else {
        cout << max(0ll, target - sum) << endl;
        return 0;
    }
}