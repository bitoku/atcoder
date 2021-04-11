#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(3 * n);
    for (int i = 0; i < 3 * n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        result += a[3 * n - 1 - (i * 2 + 1)];
    }
    cout << result << endl;
}
