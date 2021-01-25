#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> b(h, vector<int>(w));
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < a[i]; ++j) {
            int k = cnt + j;
            int y = k / w;
            int x = k % w;
            b[y][x] = i + 1;
        }
        cnt += a[i];
    }
    for (int i = 0; i < h; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < w - 1; ++j) {
                cout << b[i][j] << ' ';
            }
            cout << b[i][w-1] << endl;
        } else {
            for (int j = w - 1; j >= 1; --j) {
                cout << b[i][j] << ' ';
            }
            cout << b[i][0] << endl;
        }
    }
    cout << endl;
}
