#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    set<ll> a;
    for (int i = 0; i < n; ++i) {
        ll aa;
        cin >> aa;
        if (a.find(aa) != a.end()) {
            a.erase(aa);
        } else {
            a.insert(aa);
        }
    }
    cout << a.size() << endl;
}
