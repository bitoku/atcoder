#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll minx = LONG_LONG_MAX;
    ll maxx = 0;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        minx = min(minx, x[i]);
        maxx = max(maxx, x[i]);
    }
    ll result = LONG_LONG_MAX;
    for (int i = minx; i <= maxx; ++i) {
        ll temp = 0;
        for (int j = 0; j < n; ++j) {
            temp += (x[j] - i) * (x[j] - i);
        }
        result = min(result, temp);
    }
    cout << result << endl;
}
