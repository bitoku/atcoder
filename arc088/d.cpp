#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    string s;
    cin >> s;
    ll result = LONG_LONG_MAX;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i-1] == s[i]) continue;
        result = min(result, max((ll)i, (ll)s.size() - i));
    }
    if (result == LONG_LONG_MAX) {
        cout << s.size() << endl;
    } else {
        cout << result << endl;
    }
}