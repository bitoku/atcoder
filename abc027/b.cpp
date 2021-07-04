#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << -1 << endl;
        return 0;
    }
    ll d = sum / n;
    ll result = 0;
    for (int i = 0; i < n-1; ++i) {
        if (a[i] == d) continue;
        else {
            result++;
            a[i+1] += (a[i] - d);
        }
    }
    cout << result << endl;
}