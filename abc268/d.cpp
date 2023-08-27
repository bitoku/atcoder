#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

vector<string> split(string s, string delim) {
    vector<string> result;
    size_t pos;
    while ((pos = s.find(delim)) != string::npos) {
        result.push_back(s.substr(0, pos));
        s.erase(0, pos+delim.size());
    }
    result.push_back(s.substr(0, s.size()));
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    ll len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        len += s[i].size();
    }
    ll k = 16 - n + 1 - len;
    vector<string> t(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    sort(s.begin(), s.end());
    if (n == 1) {
        if (len < 3 || binary_search(t.begin(), t.end(), s[0])) {
            cout << -1 << endl;
            return 0;
        }
        cout << s[0] << endl;
        return 0;
    }
    do {
        for (int i = 0; i <= k; ++i) {
            string underbars = string(i, '_') + string(n-2, 'o');
            do {
                auto ubs = split(underbars, "o");
                string x = s[0];
                for (int j = 1; j < n; ++j) {
                    x += ubs[j-1] + "_" + s[j];
                }
                if (!binary_search(t.begin(), t.end(), x)) {
                    cout << x << endl;
                    return 0;
                }
            } while (next_permutation(underbars.begin(), underbars.end()));
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << -1 << endl;
}