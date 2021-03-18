#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    map<ll, int> m;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (m[a] > 0) {
            cout << "NO" << endl;
            return 0;
        }
        m[a]++;
    }
    cout << "YES" << endl;
}
