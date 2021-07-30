#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    vector<vector<int>> idx(26);
    for (int i = 0; i < n; ++i) {
        idx[s[i]-'a'].push_back(i);
    }
    string t;
    int x = -1;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 26; ++j) {
            auto it = upper_bound(idx[j].begin(), idx[j].end(), x);
            if (it == idx[j].end()) continue;
            if (k - i > n - *it) continue;
            x = *it;
            t.push_back('a' + j);
            break;
        }
    }
    cout << t << endl;
}