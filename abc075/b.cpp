#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h+2);
    vector<string> mine(h);
    for (int i = 1; i <= h; ++i) {
        cin >> s[i];
        s[i] = "." + s[i] + ".";
    }
    s[0] = string(w+2, '.');
    s[h+1] = string(w+2, '.');
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (s[i][j] == '#') {
                mine[i-1] += '#';
                continue;
            }
            int cnt = 0;
            if (s[i-1][j-1] == '#') cnt++;
            if (s[i-1][j] == '#') cnt++;
            if (s[i-1][j+1] == '#') cnt++;
            if (s[i][j-1] == '#') cnt++;
            if (s[i][j+1] == '#') cnt++;
            if (s[i+1][j-1] == '#') cnt++;
            if (s[i+1][j] == '#') cnt++;
            if (s[i+1][j+1] == '#') cnt++;
            mine[i-1] += '0' + cnt;
        }
    }
    for (int i = 0; i < h; ++i) {
        cout << mine[i] << endl;
    }
}
