#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> s(h+2);
    for (int i = 1; i <= h; ++i) {
        cin >> s[i];
        s[i] = "#" + s[i] + "#";
    }
    s[0] = string(w+2, '#');
    s[h+1] = string(w+2, '#');
    vector<string> t(h+2, string(w+2, '.'));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (
                    s[i][j] == '#' &&
                    s[i][j-1] == '#' &&
                    s[i][j+1] == '#' &&
                    s[i-1][j] == '#' &&
                    s[i-1][j-1] == '#' &&
                    s[i-1][j+1] == '#' &&
                    s[i+1][j] == '#' &&
                    s[i+1][j-1] == '#' &&
                    s[i+1][j+1] == '#'
            ) t[i][j] = '#';
            else t[i][j] = '.';
        }
    }
    vector<string> u(h+2, string(w+2, '.'));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (t[i][j] == '#') {
                u[i][j] = '#';
                u[i][j-1] = '#';
                u[i][j+1] = '#';
                u[i-1][j] = '#';
                u[i-1][j-1] = '#';
                u[i-1][j+1] = '#';
                u[i+1][j] = '#';
                u[i+1][j-1] = '#';
                u[i+1][j+1] = '#';
            }
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (s[i][j] != u[i][j]) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    cout << "possible" << endl;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cout << t[i][j];
        }
        cout << endl;
    }
}