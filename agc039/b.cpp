#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    int result = -1;
    for (int i = 0; i < n; ++i) {
        vector<int> reached(n);
        reached[i] = 1;
        vector<int> nexts = {i};
        int cnt = 1;
        bool fail = false;
        while (!nexts.empty()) {
            vector<int> new_nexts;
            cnt++;
            for (int next : nexts) {
                for (const auto x : v[next]) {
                    if (reached[x]) {
                        if (reached[x] == cnt || reached[x] == cnt - 2) continue;
                        else {
                            fail = true;
                            break;
                        }
                    }
                    new_nexts.push_back(x);
                    reached[x] = cnt;
                }
                if (fail) break;
            }
            if (fail) break;
            nexts = new_nexts;
        }
        if (fail) continue;
        result = max(result, cnt-1);
    }
    cout << result << endl;
}
