#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, l;
    cin >> n >> l;
    multiset<string> m;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        m.insert(t);
    }
    string ss;
    for (const auto& t: m) {
        ss += t;
    }
    cout << ss << endl;
}
