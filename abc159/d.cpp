#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> m(200001);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i]]++;
    }
    ll result = 0;
    for (const auto y: m) {
        result += y * (y - 1) / 2;
    }
    for (int i = 0; i < n; ++i) {
        if (m[a[i]] == 1) {
            cout << result << endl;
        } else {
            cout << result - m[a[i]] * (m[a[i]] - 1) / 2 + (m[a[i]] - 1) * (m[a[i]] - 2) / 2 << endl;
        }
    }
}
