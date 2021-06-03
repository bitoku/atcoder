#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
    vector<int> ss;
    vector<int> tt;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') ss.push_back(i);
        if (t[i] == '0') tt.push_back(i);
    }
    if (ss.size() != tt.size()) {
        cout << -1 << endl;
        return 0;
    }
    ll result = 0;
    for (int i = 0; i < ss.size(); ++i) {
        if (ss[i] != tt[i]) result++;
    }
    cout << result << endl;
}