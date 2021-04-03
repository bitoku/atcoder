#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        a[i+1] += a[i];
        b[i+1] += b[i];
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        result = max(result, a[i+1] + b[n] - b[i]);
    }
    cout << result << endl;
}
