#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<ll> w(n+1);
    vector<ll> e(n+1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') w[i+1]++;
        else e[i+1]++;
        w[i+1] += w[i];
        e[i+1] += e[i];
    }
    ll result = LONG_LONG_MAX;
    for (int i = 1; i <= n; ++i) {
        result = min(result, w[i - 1] + e[n] - e[i]);
    }
    cout << result << endl;
}
