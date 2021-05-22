#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    vector<vector<ll>> dp(a+1, vector<ll>(b+1));
    dp[0][0] = 1;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            if (i+1 <= a) dp[i+1][j] += dp[i][j];
            if (j+1 <= b) dp[i][j+1] += dp[i][j];
        }
    }
    string s;
    pair<int, int> pata = make_pair(a-1, b), patb = make_pair(a, b-1);
    while (k > 0 && pata.first >= 0 && pata.second >= 0 && patb.first >= 0 && patb.second >= 0) {
        if (k <= dp[pata.first][pata.second]) {
            s.push_back('a');
            pair<int, int> newpata = make_pair(pata.first - 1, pata.second);
            pair<int, int> newpatb = make_pair(pata.first, pata.second - 1);
            pata = newpata;
            patb = newpatb;
        } else {
            s.push_back('b');
            k -= dp[pata.first][pata.second];
            pair<int, int> newpata = make_pair(patb.first - 1, patb.second);
            pair<int, int> newpatb = make_pair(patb.first, patb.second - 1);
            pata = newpata;
            patb = newpatb;
        }
    }
    if (k == 0) {
        pata.first++;
        for (int i = 0; i < pata.first; ++i) {
            s.push_back('a');
        }
        for (int i = 0; i < pata.second; ++i) {
            s.push_back('b');
        }
    } else if (pata.first < 0) {
        for (int i = 0; i < pata.second; ++i) {
            s.push_back('b');
        }
    } else {
        for (int i = 0; i < patb.first; ++i) {
            s.push_back('a');
        }
    }
    cout << s << endl;
}