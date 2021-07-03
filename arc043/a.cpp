#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> s(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sum += s[i];
    }
    sort(s.begin(), s.end());
    ll t = s.back() - s.front();
    if (t == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << setprecision(12) << (ld)b / t << ' ' << (ld)a - (ld)sum * b / n / t << endl;
}