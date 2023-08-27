#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    vector<pair<int, int>> a, b;
    set<pair<int, int>> x;
    ll ha, wa, hb, wb, hx, wx;

    cin >> ha >> wa;
    for (int i = 0; i < ha; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < wa; ++j) {
            if (s[j] == '#') a.emplace_back(i, j);
        }
    }

    cin >> hb >> wb;
    for (int i = 0; i < hb; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < wb; ++j) {
            if (s[j] == '#') b.emplace_back(i, j);
        }
    }

    cin >> hx >> wx;
    for (int i = 0; i < hx; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < wx; ++j) {
            if (s[j] == '#') x.insert(make_pair(i, j));
        }
    }
    for (auto xa: x) {
        for (auto xb: x) {
            auto da = make_pair(xa.first - a[0].first, xa.second - a[0].second);
            auto db = make_pair(xb.first - b[0].first, xb.second - b[0].second);
            set<pair<int, int>> s;
            for (auto & ai : a) {
                s.insert(make_pair(ai.first + da.first, ai.second + da.second));
            }
            for (auto & bi : b) {
                s.insert(make_pair(bi.first + db.first, bi.second + db.second));
            }
            if (x == s) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}