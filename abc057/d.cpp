#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll dp[100][100];

ll pascal(ll a, ll b) {
    if (dp[a][b]) return dp[a][b];
    if (b == 0 || a == b) return 1;
    if (b == 1) return a;
    dp[a][b] = pascal(a-1, b-1) + pascal(a-1, b);
    return dp[a][b];
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    pair<ll, ll> result = {};
    for (int i = n-1; i >= n-a; --i) {
        result.first += v[i];
        result.second++;
    }
    ll vmin = v[n-a];
    ll m = 0;
    for (int i = 0; i < n-a; ++i) {
        if (v[i] == vmin) m++;
    }
    ll r = 0;
    for (int i = n-a; i < n; ++i) {
        if (v[i] == vmin) r++;
    }
    ll cnt = 0;
    if (r == a) {
        for (int i = r; i <= min(b, m+r); ++i) {
            cnt += pascal(m+r, i);
        }
    } else {
        cnt += pascal(m+r, r);
    }
    printf("%lf\n", (double)result.first / result.second);
    cout << cnt << endl;
}
