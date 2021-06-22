#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll l, r;
    cin >> l >> r;
    vector<ll> x(r+1);
    vector<ll> x2(r+1);
    ll result = 0;
    for (int i = r; i >= 2; --i) {
        x[i] = r / i - (l - 1) / i;
    }
    for (int i = r; i >= 2; --i) {
        x2[i] = x[i] * x[i];
        for (int j = 2 * i; j <= r; j += i) {
            x2[i] -= x2[j];
        }
        result += x2[i];
    }
    for (int i = max(2ll, l); i <= r; ++i) {
        result -= 2 * x[i] - 1;
    }
    cout << result << endl;
}