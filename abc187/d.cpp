#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll vote = 0;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        vote -= a;
        x[i] = 2 * a + b;
    }
    sort(x.begin(), x.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        vote += x[i];
        if (vote > 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
}
