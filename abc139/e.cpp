#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    vector<int> idx(n);
    ll cnt = 0;
    while (true) {
        cnt++;
        vector<bool> game(n);
        for (int i = 0; i < n; ++i) {
            if (game[i] || idx[i] == n - 1) continue;
            int j = a[i][idx[i]];
            if (game[j] || idx[j] == n - 1) continue;
            if (a[j][idx[j]] == i) {
                idx[i]++;
                idx[j]++;
                game[i] = true;
                game[j] = true;
            }
        }
        if (!any_of(game.begin(), game.end(), [](bool x) {return x;})) {
            cout << -1 << endl;
            return 0;
        }
        if (all_of(idx.begin(), idx.end(), [n](int x) {return x == n-1;})) {
            break;
        }
    }
    cout << cnt << endl;
}