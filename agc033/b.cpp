#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 06/28

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    int sy, sx;
    cin >> sy >> sx;
    string s, t;
    cin >> s;
    cin >> t;
    int left = 1, right = W;
    int bottom = H, top = 1;
    for (int i = N - 1; i >= 0; --i) {
        if (t[i] == 'L') {
            right = min(W, right+1);
        }
        if (t[i] == 'R') {
            left = max(1, left-1);
        }
        if (t[i] == 'U') {
            bottom = min(H, bottom+1);
        }
        if (t[i] == 'D') {
            top = max(1, top - 1);
        }

        if (s[i] == 'L') {
            left++;
        }
        if (s[i] == 'R') {
            right--;
        }
        if (s[i] == 'U') {
            top++;
        }
        if (s[i] == 'D') {
            bottom--;
        }
        if (left > right || bottom < top) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (left <= sx && sx <= right && top <= sy && sy <= bottom) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}