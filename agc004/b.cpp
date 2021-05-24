#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll result = LONG_LONG_MAX;
    vector<ll> b = a;
    for (int i = 0; i < n; ++i) {
        ll temp = i * x;
        for (int j = 0; j < n; ++j) {
            temp += b[j];
            b[j] = min(b[j], a[(j+i+1) % n]);
        }
        result = min(result, temp);
    }
    cout << result << endl;
}