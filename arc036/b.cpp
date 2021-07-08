#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int left = 0;
    ll result = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (h[i-1] > h[i] && h[i] < h[i+1]) {
            result = max(result, i - left + 1ll);
            left = i;
        }
    }
    result = max(result, n - left);
    cout << result << endl;
}