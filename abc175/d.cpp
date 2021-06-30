#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 07/01

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<ll> cycle(n);
    vector<ll> sum(n);
    for (int i = 0; i < n; ++i) {
        sum[i] = c[i];
        cycle[i] = 1;
        int next = p[i];
        while (next != i) {
            sum[i] += c[next];
            cycle[i]++;
            next = p[next];
        }
    }
    ll result = LONG_LONG_MIN;
    for (int i = 0; i < n; ++i) {
        ll x = c[i];
        ll rest = k - 1;
        ll temp = x;
        int j = p[i];
        if (sum[j] > 0) {
            x += rest / cycle[j] * sum[j];
            rest %= cycle[i];
        }
        temp = max(x, temp);
        for (int _ = 0; _ < min(rest, cycle[j]); ++_) {
            x += c[j];
            j = p[j];
            temp = max(x, temp);
        }
        result = max(temp, result);
    }
    cout << result << endl;
}