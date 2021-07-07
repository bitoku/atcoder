#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> result;
    for (int i = min(200ll, n); i >= 1; --i) {
        ll a = n - i;
        ll f = 0;
        while (a > 0) {
            f += a % 10;
            a /= 10;
        }
        if (f == i) result.push_back(n - i);
    }
    cout << result.size() << endl;
    for (auto x: result) {
        cout << x << endl;
    }
}