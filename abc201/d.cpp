#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll h, w;

vector<vector<pair<int, int>>> dp;

pair<int, int> dfs(vector<string>& s, int hh, int ww) {
    pair<int, int> x = {0, 0};
    pair<int, int> result = {0, 0};
    if (dp[hh][ww] != make_pair(INT_MAX, INT_MAX)) return dp[hh][ww];
    if ((hh + ww) % 2 == 0) {
        if (s[hh][ww] == '+') x.second += 1;
        else x.second -= 1;
        if (hh + 1 < h && ww + 1 < w) {
            pair<int, int> p = dfs(s, hh + 1, ww);
            pair<int, int> q = dfs(s, hh, ww + 1);
            if (p.second - p.first < q.second - q.first) {
                result = p;
            } else {
                result = q;
            }
        } else if (hh + 1 < h) {
            result = dfs(s, hh + 1, ww);
        } else if (ww + 1 < w){
            result = dfs(s, hh, ww+1);
        }
    } else {
        if (s[hh][ww] == '+') x.first += 1;
        else x.first -= 1;
        if (hh + 1 < h && ww + 1 < w) {
            pair<int, int> p = dfs(s, hh + 1, ww);
            pair<int, int> q = dfs(s, hh, ww + 1);
            if (p.first - p.second < q.first - q.second) {
                result = p;
            } else {
                result = q;
            }
        } else if (hh + 1 < h) {
            result = dfs(s, hh + 1, ww);
        } else if (ww + 1 < w) {
            result = dfs(s, hh, ww+1);
        }
    }
    dp[hh][ww] = make_pair(result.first + x.first, result.second + x.second);
    return dp[hh][ww];
}

int main() {
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    dp.resize(h, vector<pair<int,int>>(w, make_pair(INT_MAX, INT_MAX)));
    dfs(s, 0, 0);
    if (s[0][0] == '+') dp[0][0].second -= 1;
    else dp[0][0].second += 1;
//    for (int i = 0; i < h; ++i) {
//        for (int j = 0; j < w; ++j) {
//            cout << '(' << dp[i][j].first << ',' << dp[i][j].second << ')' << ' ';
//        }
//        cout << endl;
//    }
    if (dp[0][0].first > dp[0][0].second) {
        cout << "Takahashi" << endl;
    } else if (dp[0][0].first < dp[0][0].second) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
}