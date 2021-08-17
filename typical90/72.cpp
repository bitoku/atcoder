#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int dfs(vector<string>& v, int r, int c, int step, vector<vector<int>>& route) {
    if (route[r][c] > 0) {
        if (step - route[r][c] > 2) return step - route[r][c];
        else return -1;
    }

    route[r][c] = step;
    int result = -1;
    if (v[r+1][c] == '.') result = max(result, dfs(v, r+1, c, step+1, route));
    if (v[r-1][c] == '.') result = max(result, dfs(v, r-1, c, step+1, route));
    if (v[r][c+1] == '.') result = max(result, dfs(v, r, c+1, step+1, route));
    if (v[r][c-1] == '.') result = max(result, dfs(v, r, c-1, step+1, route));
    route[r][c] = 0;
    return result;
}

int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> v(h + 2);
    for (int i = 1; i <= h; ++i) {
        cin >> v[i];
        v[i] = "#" + v[i] + "#";
    }
    v[0] = string(w + 2, '#');
    v[h+1] = string(w + 2, '#');
    vector<vector<int>> route(h+2, vector<int>(w+2));
    int result = -1;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (v[i][j] == '#') continue;
            result = max(result, dfs(v, i, j, 1, route));
        }
    }
    cout << result << endl;
}