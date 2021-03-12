#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        for (int j = 0; j < v.size() + 1; ++j) {
            if (j == v.size()) {
                vector<int> vv = {w};
                v.push_back(vv);
            }
            if (w <= v[j].back()) {
                v[j].push_back(w);
                break;
            }
        }
    }
    cout << v.size() << endl;
}
