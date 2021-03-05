#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    vector<ll> b(c);
    vector<ll> result(c);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        result[a[i]] += (i - b[a[i]]) * b[a[i]];
        result[a[i]] += i + 1;
        b[a[i]] = i + 1;
    }
    for (int i = 0; i < c; ++i) {
        result[i] += max(n - b[i], 0ll) * b[i];
    }
    for (int i = 0; i < c; ++i) {
        cout << result[i] << endl;
    }
}
