#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll a[26] = {};
    for (int i = 0; i < 26; ++i) {
        a[i] = LONG_LONG_MAX;
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ll b[26] = {};
        for (int j = 0; j < s.size(); ++j) {
            b[s[j] - 'a']++;
        }
        for (int j = 0; j < 26; ++j) {
            a[j] = min(a[j], b[j]);
        }
    }
    string result;
    for (int i = 0; i < 26; ++i) {
        result += string(a[i], 'a' + i);
    }
    cout << result << endl;
}
