#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, k, c;
    string s;
    cin >> n >> k >> c;
    cin >> s;
    vector<ll> l(k);
    vector<ll> r(k);
    int x = INT_MIN;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (x + c < i && s[i] == 'o') {
            l[j++] = i;
            x = i;
            if (j == k) break;
        }
    }
    x = INT_MAX;
    j = k - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (x - c > i && s[i] == 'o') {
            r[j--] = i;
            x = i;
            if (j == -1) break;
        }
    }
    for (int i = 0; i < k; ++i) {
        if (l[i] == r[i]) cout << l[i]+1 << endl;
    }
}