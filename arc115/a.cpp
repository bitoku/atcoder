#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(n);
    ll o = 0, e = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '0') p[i].first++;
            else p[i].second++;
        }
        if (p[i].first % 2 == 0) e++;
        else o++;
    }
    cout << e * o << endl;
}