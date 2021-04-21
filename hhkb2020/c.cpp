#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    set<ll> s;
    for (int i = 0; i <= 200000; ++i) {
        s.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        s.erase(p[i]);
        cout << *(s.begin()) << endl;
    }
}
