#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        pos[a].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        if (pos[i].empty()) {
            cout << i << endl;
            return 0;
        }
        if (m <= pos[i][0]) {
            cout << i << endl;
            return 0;
        }
        for (int j = 1; j < pos[i].size(); ++j) {
            if (pos[i][j] - pos[i][j-1] > m) {
                cout << i << endl;
                return 0;
            }
        }
        if (pos[i][pos[i].size() - 1] < n - m) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
}

//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    set<ll> excluded;
//    for (int i = 0; i <= n; ++i) {
//        excluded.insert(i);
//    }
//    int cnt[1500001] = {};
//    for (int i = 0; i < m; ++i) {
//        cnt[a[i]]++;
//        excluded.erase(a[i]);
//    }
//    ll k = LONG_LONG_MAX;
//    k = min(k, *excluded.begin());
//    for (int i = m; i < n; ++i) {
//        cnt[a[i-m]]--;
//        if (cnt[a[i-m]] == 0) {
//            excluded.insert(a[i-m]);
//        }
//        cnt[a[i]]++;
//        excluded.erase(a[i]);
//        k = min(k, *excluded.begin());
//    }
//    cout << k << endl;
//}
