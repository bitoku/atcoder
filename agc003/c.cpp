#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    ll cnt = 0;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        int x = (int)distance(b.begin(), it);
        while (s.find(x) != s.end()) {
            ++x;
        }
        s.insert(x);
        if ((x - i) % 2 != 0) cnt++;
    }
    cout << cnt / 2 << endl;
}