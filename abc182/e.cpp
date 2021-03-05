#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<string> vert(h, string(w, '.'));
    vector<string> hori(h, string(w, '.'));
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        vert[a][b] = 'o';
        hori[a][b] = 'o';
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        vert[a][b] = '#';
        hori[a][b] = '#';
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w-1; ++j) {
            if (vert[i][j] == 'o' && vert[i][j+1] != '#') {
                vert[i][j+1] = 'o';
            }
        }
        for (int j = w-1; j >= 1; --j) {
            if (vert[i][j] == 'o' && vert[i][j-1] != '#') {
                vert[i][j-1] = 'o';
            }
        }
    }
    for (int j = 0; j < w; ++j) {
        for (int i = 0; i < h - 1; ++i) {
            if (hori[i][j] == 'o' && hori[i + 1][j] != '#') {
                hori[i + 1][j] = 'o';
            }
        }
        for (int i = h - 1; i >= 1; --i) {
            if (hori[i][j] == 'o' && hori[i - 1][j] != '#') {
                hori[i-1][j] = 'o';
            }
        }
    }
    ll cnt = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (vert[i][j] == 'o' || hori[i][j] == 'o') cnt++;
        }
    }
    cout << cnt << endl;
}
