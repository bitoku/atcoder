#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll q;
    cin >> q;
    bool flipped = false;
    for (int i = 0; i < q; ++i) {
        ll t, a, b;
        cin >> t >> a >> b;
        if (t == 2) {
            flipped = !flipped;
        }
        if (t == 1) {
            if (flipped) {
                if (a <= n) a += n;
                else if (n < a) a -= n;
                if (b <= n) b += n;
                else if (n < b) b -= n;
            }
            a--; b--;
            swap(s[a], s[b]);
        }
    }
    if (flipped) {
        cout << s.substr(n, n) << s.substr(0, n) << endl;
    } else {
        cout << s << endl;
    }
}