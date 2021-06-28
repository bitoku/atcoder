#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 06/28

int main() {
    ll n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<set<int>> del(n);
    for (int i = 0; i < n; ++i) {
        deque<int> d;
        d.push_back(i);
        del[i].insert(i);
        while (!d.empty()) {
            int cur = d.front(); d.pop_front();
            for (int j = 0; j < n; ++j) {
                if (v[cur][j] == '0') continue;
                if (del[i].find(j) != del[i].end()) continue;
                del[i].insert(j);
                d.push_back(j);
            }
        }
    }
    vector<vector<int>> m(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (del[j].find(i) == del[j].end()) continue;
            m[i].push_back(j);
        }
    }
    ld result = 0;
    for (int i = 0; i < n; ++i) {
        result += (ld)1 / m[i].size();
    }
    cout << setprecision(12) << result << endl;
}