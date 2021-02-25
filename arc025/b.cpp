#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> white(h+1, vector<int>(w+1));
    vector<vector<int>> black(h+1, vector<int>(w+1));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if ((i + j) % 2 == 1) {
                cin >> white[i][j];
            } else {
                cin >> black[i][j];
            }
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            white[i][j] += white[i][j-1];
            black[i][j] += black[i][j-1];
        }
    }
    for (int j = 1; j <= w; ++j) {
        for (int i = 1; i <= h; ++i) {
            white[i][j] += white[i-1][j];
            black[i][j] += black[i-1][j];
        }
    }
    ll result = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = i+1; k <= h; ++k) {
                for (int l = j+1; l <= w; ++l) {
                    if (
                            white[k][l] - white[k][j] - white[i][l] + white[i][j] ==
                            black[k][l] - black[k][j] - black[i][l] + black[i][j]
                            ) {
                        result = max(result, (ll)(k - i) * (l - j));
                    }
                }
            }
        }
    }
    cout << result << endl;
}
