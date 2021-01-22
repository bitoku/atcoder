#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> ss(h+2);
    for (int i = 1; i <= h; ++i) {
        string s;
        cin >> s;
        ss[i] = "." + s + ".";
    }
    ss[0] = string(w+2, '.');
    ss[h+1] = string(w+2, '.');
    bool isolated = false;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (ss[i][j] == '.') continue;
            if (
                ss[i-1][j] == '.' &&
                ss[i][j-1] == '.' &&
                ss[i+1][j] == '.' &&
                ss[i][j+1] == '.'
            ) {
                isolated = true;
                break;
            }
        }
        if (isolated) break;
    }
    if (isolated) cout << "No" << endl;
    else cout << "Yes" << endl;
}
