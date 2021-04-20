#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, c;
    cin >> n >> c;
    vector<ll> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    int r = 0;
    ll result = 0;
    for (int i = n-1; i >= r; --i) {
        if (i != r && l[i] + l[r] + 1 <= c) {
            r++;
            result++;
        } else {
            result++;
        }
    }
    cout << result << endl;
}
