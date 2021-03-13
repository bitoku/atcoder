#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> x(m);
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector<ll> a(m-1);
    for (int i = 0; i < m - 1; ++i) {
        a[i] = x[i+1] - x[i];
    }
    sort(a.begin(), a.end());
    ll result = 0;
    for (int i = 0; i < m - n; ++i) {
        result += a[i];
    }
    cout << result << endl;
}
