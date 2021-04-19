#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll result = 0;
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (mx < a[i]) {
            result++;
        }
        mx = max(a[i], mx);
    }
    cout << result << endl;
}
