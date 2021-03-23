#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll result = 0;
    ll mx = 0;
    ll sum = 0;
    ll pos = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, sum);
        result = max(result, pos + mx);
        pos += sum;
    }
    cout << result << endl;
}
