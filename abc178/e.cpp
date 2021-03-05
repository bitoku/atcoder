#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> minus(n);
    vector<ll> plus(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        minus[i] = y - x;
        plus[i] = y + x;
    }
    ll plusmin = LONG_LONG_MAX, plusmax = 0;
    ll minusmin = LONG_LONG_MAX, minusmax = 0;
    for (int i = 0; i < n; ++i) {
        plusmin = min(plusmin, plus[i]);
        plusmax = max(plusmax, plus[i]);
        minusmin = min(minusmin, minus[i]);
        minusmax = max(minusmax, minus[i]);
    }
    cout << max(plusmax - plusmin, minusmax - minusmin) << endl;
}
