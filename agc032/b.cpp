#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    deque<int> a(n);
    iota(a.begin(), a.end(), 1);
    vector<vector<int>> group(n / 2);
    if (n % 2 == 1) {
        vector<int> top = {a.back()};
        group.push_back(top);
        a.pop_back();
    }
    for (int i = 0; i < n / 2; ++i) {
        group[i].push_back(a.front());
        group[i].push_back(a.back());
        a.pop_back();
        a.pop_front();
    }
    vector<pair<int, int>> out;
    for (int i = 0; i < group.size(); ++i) {
        for (int j = i + 1; j < group.size(); ++j) {
            for (const auto x : group[i]) {
                for (const auto y : group[j]) {
                    out.emplace_back(x, y);
                }
            }
        }
    }
    cout << out.size() << endl;
    for (int i = 0; i < out.size(); ++i) {
        printf("%d %d\n", out[i].first, out[i].second);
    }
}
