#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> s(H);
    for (int i = 0; i < H; ++i) {
        cin >> s[i];
    }
    ll result = 1;
    for (int i = 0; i < W; ++i) {
        int x = 0;
        for (int j = 0; j <= i && i - j < W && j < H; ++j) {
            int w = i - j;
            int h = j;
            if (s[h][w] == '.') continue;
            if (s[h][w] == 'R') {
                if (x == 0 || x == 1) x = 1;
                else x = -1;
                continue;
            }
            if (s[h][w] == 'B') {
                if (x == 0 || x == 2) x = 2;
                else x = -1;
                continue;
            }
        }
        if (x == 0) {
            result *= 2;
            result %= mod;
        }
        if (x == -1) {
            result = 0;
        }
    }
    for (int i = 1; i < H; ++i) {
        int x = 0;
        for (int j = 0; j < W && i + j < H; ++j) {
            int w = W - 1 - j;
            int h = i + j;
            if (s[h][w] == '.') continue;
            if (s[h][w] == 'R') {
                if (x == 0 || x == 1) x = 1;
                else x = -1;
                continue;
            }
            if (s[h][w] == 'B') {
                if (x == 0 || x == 2) x = 2;
                else x = -1;
                continue;
            }
        }
        if (x == 0) {
            result *= 2;
            result %= mod;
        }
        if (x == -1) {
            result = 0;
        }
    }
    cout << result << endl;
}