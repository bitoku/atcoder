#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> left(n), right(n);
    vector<ll> b;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        if (it == b.end()) {
            b.push_back(a[i]);
            left[i] = b.size();
        }
        else {
            *it = a[i];
            left[i] = distance(b.begin(), it) + 1;
        }
    }
    b.clear();
    for (int i = n-1; i >= 0; --i) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        if (it == b.end()) {
            b.push_back(a[i]);
            right[i] = b.size();
        }
        else {
            *it = a[i];
            right[i] = distance(b.begin(), it) + 1;
        }
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        result = max(result, left[i] + right[i]);
    }
    cout << result - 1 << endl;
}