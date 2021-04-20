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
    char before = 'x';
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (before != s[i]) {
            v.push_back(1);
            before = s[i];
        } else {
            v[v.size() - 1]++;
        }
    }
    if (v.size() == 1) {
        cout << v[0] - 0.5 << endl;
        return 0;
    }
    ll mi = -1;
    ll mx = 0;
    for (int i = 1; i < v.size(); i += 2) {
        if (v[i] > mx) {
            mi = i;
            mx = v[i];
        }
    }
    v[mi]++;
    ld result = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (i % 2 == 0) {
            result += v[i];
        } else {
            for (int j = 0; j < v[i]; ++j) {
                result += 1 / (ld)(j + 2);
            }
        }
    }
    cout << setprecision(12) << result - 1 << endl;
}
