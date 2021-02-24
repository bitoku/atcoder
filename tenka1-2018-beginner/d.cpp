#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int k = 0;
    for (int i = 1; i * (i + 1) <= 2 * n; ++i) {
        if (i * (i + 1) == 2 * n) {
            k = i + 1;
            break;
        }
    }
    if (k == 0) {
        cout << "No" << endl;
        return 0;
    }
    vector<vector<int>> v(k);
    int cnt = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = i+1; j < k; ++j) {
            v[i].push_back(cnt);
            v[j].push_back(cnt);
            cnt++;
        }
    }
    cout << "Yes" << endl;
    cout << v.size() << endl;
    for (int i = 0; i < k; ++i) {
        cout << v[i].size();
        for (int j = 0; j < v[i].size(); ++j) {
            cout << ' ' << v[i][j];
        }
        cout << endl;
    }
}
