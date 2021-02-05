#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    int coins[500][500];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> coins[i][j];
        }
    }
    int ope[250000][4] = {0};
    int cnt = 0;
    for (int i = 0; i < h; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < w; ++j) {
                if (coins[i][j] % 2 == 0) continue;
                if (j == w - 1) {
                    if (i + 1 >= h) continue;
                    coins[i][j]--;
                    coins[i+1][j]++;
                    ope[cnt][0] = i+1;
                    ope[cnt][1] = j+1;
                    ope[cnt][2] = i+2;
                    ope[cnt][3] = j+1;
                    cnt++;
                } else {
                    coins[i][j]--;
                    coins[i][j+1]++;
                    ope[cnt][0] = i+1;
                    ope[cnt][1] = j+1;
                    ope[cnt][2] = i+1;
                    ope[cnt][3] = j+2;
                    cnt++;
                }
            }
        } else {
            for (int j = w - 1; j >= 0; --j) {
                if (coins[i][j] % 2 == 0) continue;
                if (j == 0) {
                    if (i + 1 >= h) continue;
                    coins[i][j]--;
                    coins[i+1][j]++;
                    ope[cnt][0] = i+1;
                    ope[cnt][1] = j+1;
                    ope[cnt][2] = i+2;
                    ope[cnt][3] = j+1;
                    cnt++;
                } else {
                    coins[i][j]--;
                    coins[i][j-1]++;
                    ope[cnt][0] = i+1;
                    ope[cnt][1] = j+1;
                    ope[cnt][2] = i+1;
                    ope[cnt][3] = j;
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i) {
        printf("%d %d %d %d\n", ope[i][0], ope[i][1], ope[i][2], ope[i][3]);
    }
}
