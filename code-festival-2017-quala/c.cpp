#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    int charcnt[26] = {0};
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char a;
            cin >> a;
            charcnt[a - 'a']++;
        }
    }
    int g[3] = {
      (h / 2) * (w / 2),
      (h % 2) * (w / 2) + (w % 2) * (h / 2),
      (h % 2) * (w % 2),
    };
    int k[3] = {
      4, 2, 1
    };
    for (int i = 0; i < 3; ++i) {
        for (int &c : charcnt) {
            while (g[i] > 0 && c >= k[i]) {
                g[i]--;
                c -= k[i];
            }
        }
        if (g[i] > 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (charcnt[i] > 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
