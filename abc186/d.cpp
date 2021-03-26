#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<>());
    vector<ll> b(n+1);
    for (int i = 0; i < n; ++i) {
        b[i+1] = b[i] + a[i];
    }
    ll result = n * b[n-1];
    for (int i = 0; i < n - 1; ++i) {
        result -= (i + 1) * a[i] + b[n] - b[i + 1];
    }
    cout << result << endl;
}
