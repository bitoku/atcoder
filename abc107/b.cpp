#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> ss;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        if (s.find('#') == string::npos) continue;
        ss.push_back(s);
    }
    for (int i = 0; i < w; ++i) {
        bool all_white = true;
        for (auto & s : ss) {
            if (s[i] == '#') {
                all_white = false;
                break;
            }
        }
        if (all_white) {
            for (auto & s : ss) {
                s[i] = 'x';
            }
        }
    }
    for (auto & s : ss) {
        for (int j = 0; j < w; ++j) {
            if (s[j] == 'x') continue;
            cout << s[j];
        }
        cout << endl;
    }
    cout << endl;
}
