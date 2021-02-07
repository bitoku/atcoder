#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    int cnt = 0;
    for (int i = 0; i < h-1; ++i) {
        for (int j = 0; j < w-1; ++j) {
            int x = 0;
            if (s[i][j] == '#') x++;
            if (s[i+1][j] == '#') x++;
            if (s[i][j+1] == '#') x++;
            if (s[i+1][j+1] == '#') x++;
            if (x == 1 || x == 3) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
