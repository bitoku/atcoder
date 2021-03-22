#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string n;
    cin >> n;
    ll result = 20;
    for (int i = 1; i < (1ll << n.size()); ++i) {
        string s;
        for (int j = 0; j < n.size(); ++j) {
            if (i & (1ll << j)) s.push_back(n[j]);
        }
        if (stoll(s) % 3 == 0) {
            result = min(result, (ll)(n.size() - s.size()));
        }
    }
    if (result == 20) cout << -1 << endl;
    else cout << result << endl;
}
