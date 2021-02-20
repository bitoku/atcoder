#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        sort(n.begin(), n.end(), greater<>{});
        ll x = stoll(n);
        sort(n.begin(), n.end());
        ll y = stoll(n);
        n = to_string(x - y);
    }
    cout << n << endl;
}
