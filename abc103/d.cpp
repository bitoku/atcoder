#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> bad(m);
    for (int i = 0; i < m; ++i) {
        cin >> bad[i].second >> bad[i].first;
    }
    sort(bad.begin(), bad.end());
    int cnt = 0;
    int fall = 0;
    for (int i = 0; i < m; ++i) {
        if (bad[i].second < fall && fall <= bad[i].first) continue;
        fall = bad[i].first;
        cnt++;
    }
    cout << cnt << endl;
}
