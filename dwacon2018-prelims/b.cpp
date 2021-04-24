#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll cnt = 0;
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '2') cnt++;
        if (s[i] == '5') cnt--;
        if (cnt < 0) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, cnt);
    }
    if (cnt > 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}