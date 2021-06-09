#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> A(n);
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        A[i] = make_pair(a, b);
    }
    ll result = 0;
    for (auto [a, b]: A) {
        if ((a | k) == k) result += b;
    }
    for (int i = 30; i >= 0; --i) {
        if ((k & (1 << i)) == 0) continue;
        ll x = (k ^ (1ll << i)) | ((1ll << i) - 1);
        ll temp = 0;
        for (auto [a, b]: A) {
            if ((a | x) == x) temp += b;
        }
        result = max(result, temp);
    }
    cout << result << endl;
}