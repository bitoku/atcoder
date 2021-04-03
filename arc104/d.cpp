#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<ll> a(n+1), g(n+1), t(n+1), c(n+1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') a[i+1]++;
        if (s[i] == 'C') c[i+1]++;
        if (s[i] == 'G') g[i+1]++;
        if (s[i] == 'T') t[i+1]++;
        a[i+1] += a[i];
        c[i+1] += c[i];
        g[i+1] += g[i];
        t[i+1] += t[i];
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (a[j] - a[i] == t[j] - t[i] && c[j] - c[i] == g[j] - g[i]) {
                result++;
            }
        }
    }
    cout << result << endl;
}
