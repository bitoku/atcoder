#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n+2);
    ll all = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        all += abs(a[i] - a[i-1]);
    }
    all += abs(a[n]);
    for (int i = 1; i <= n; ++i) {
        cout << all - abs(a[i] - a[i-1]) - abs(a[i+1] - a[i]) + abs(a[i+1] - a[i-1]) << endl;
    }
}
