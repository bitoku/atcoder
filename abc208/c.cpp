#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });
    ll x = k / n;
    ll y = k % n;
    vector<ll> result(n);
    for (int i = 0; i < n; ++i) {
        if (i < y) {
            result[idx[i]] = x + 1;
        } else {
            result[idx[i]] = x;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << result[i] << endl;
    }
}