#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string a;
    string b;
    cin >> a >> b;
    int n = a.size();
    string c;
    string d;
    int chars[26] = {};
    for (int i = 0; i < n; ++i) {
        chars[a[i]-'a']++;
        if (a[i] != b[i]) {
            c.push_back(a[i]);
            d.push_back(b[i]);
        }
    }
    int m = c.size();
    if (m > 6) {
        cout << "NO" << endl;
        return 0;
    }
    if (m == 0) {
        for (int i : chars) {
            if (i <= 1) continue;
            cout << "YES" << endl;
            return 0;
        }
        cout << "NO" << endl;
        return 0;
    }
    vector<pair<int, int>> pats;
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            pats.emplace_back(i, j);
        }
    }
    for (int i : chars) {
        if (i <= 1) continue;
        pats.emplace_back(0, 0);
        break;
    }
    for (const auto [s1, t1]: pats) {
        for (const auto [s2, t2]: pats) {
            for (const auto [s3, t3]: pats) {
                string e = c;
                swap(e[s1], e[t1]);
                swap(e[s2], e[t2]);
                swap(e[s3], e[t3]);
                if (e == d) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
}
