#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    set<ll> s;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        s.insert(x);
    }
    while (s.size() != 1) {
        ll x = *s.begin();
        ll X = *s.rbegin();
        s.erase(X);
        s.insert(X - x);
    }
    cout << *s.begin() << endl;
}
