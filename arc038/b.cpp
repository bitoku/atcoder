#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int h, w;
int judges[101][101];

bool judge(const vector<string>& s, int i, int j) {
    if (i >= h || j >= w) return true;
    if (judges[i][j] != -1) return judges[i][j] == 1;
    if (s[i][j] == '#') return true;
    judges[i][j] = !(judge(s, i+1, j) & judge(s, i, j+1) & judge(s, i+1, j+1)) ? 1 : 0;
    return judges[i][j] == 1;
}

int main() {
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            judges[i][j] = -1;
        }
    }
    if (judge(s, 0, 0)) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}

//int main() {
//    int h, w;
//    cin >> h >> w;
//    vector<string> s(h);
//    for (int i = 0; i < h; ++i) {
//        cin >> s[i];
//    }
//    vector<vector<bool>> a(h, vector<bool>(w));
//    for (int i = h - 1; i >= 0; --i) {
//        for (int j = w - 1; j >= 0; --j) {
//            if (s[i][j] == '#') continue;
//            if (i + 1 == h && j + 1 == w) {
//                a[i][j] = false;
//            } else if (i + 1 == h) {
//                if (s[i][j+1] == '#') {
//                    a[i][j] = false;
//                } else {
//                    a[i][j] = !a[i][j+1];
//                }
//            } else if (j + 1 == w) {
//                if (s[i+1][j] == '#') {
//                    a[i][j] = false;
//                } else {
//                    a[i][j] = !a[i+1][j];
//                }
//            } else {
//                if (s[i+1][j] == '#' && s[i][j+1] == '#' && s[i+1][j+1] == '#') {
//                    a[i][j] = false;
//                } else if (s[i+1][j] == '#' && s[i+1][j+1] == '#') {
//                    a[i][j] = !a[i][j+1];
//                } else if (s[i+1][j] == '#' && s[i][j+1] == '#') {
//                    a[i][j] = !a[i+1][j+1];
//                } else if (s[i][j+1] == '#' && s[i+1][j+1] == '#') {
//                    a[i][j] = !a[i+1][j];
//                } else if (s[i+1][j] == '#') {
//                    a[i][j] = !(a[i][j+1] & a[i+1][j+1]);
//                } else if (s[i][j+1] == '#') {
//                    a[i][j] = !(a[i+1][j] & a[i+1][j+1]);
//                } else if (s[i+1][j+1] == '#') {
//                    a[i][j] = !(a[i+1][j] & a[i][j+1]);
//                } else {
//                    a[i][j] = !(a[i+1][j] & a[i][j+1] & a[i+1][j+1]);
//                }
//            }
//        }
//    }
//    if (a[0][0]) {
//        cout << "First" << endl;
//    } else {
//        cout << "Second" << endl;
//    }
//}
