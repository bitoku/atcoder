#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    vector<int> b(10);
    vector<int> order(10);
    for (int i = 0; i < 10; ++i) {
        cin >> b[i];
        order[b[i]] = i;
    }
    ll n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [&](string& s, string& t) {
        if (s.size() < t.size()) return true;
        if (s.size() > t.size()) return false;
        for (int i = 0; i < s.size(); ++i) {
            if (order[s[i]-'0'] < order[t[i]-'0']) return true;
            if (order[s[i]-'0'] > order[t[i]-'0']) return false;
        }
        return false;
    });
    for (auto& x: a) {
        cout << x << endl;
    }
}