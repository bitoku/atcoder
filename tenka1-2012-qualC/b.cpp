#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    int royalcand[4][5] = {};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            royalcand[i][j] = -1;
        }
    }
    vector<string> v;
    vector<int> take;
    for (int i = 0; i < s.size(); i += 2) {
        int suit;
        if (s[i] == 'S') suit = 0;
        else if (s[i] == 'H') suit = 1;
        else if (s[i] == 'D') suit = 2;
        else if (s[i] == 'C') suit = 3;

        int num;
        if (s[i+1] == '2') num = 2;
        else if (s[i+1] == '3') num = 3;
        else if (s[i+1] == '4') num = 4;
        else if (s[i+1] == '5') num = 5;
        else if (s[i+1] == '6') num = 6;
        else if (s[i+1] == '7') num = 7;
        else if (s[i+1] == '8') num = 8;
        else if (s[i+1] == '9') num = 9;
        else {
            if (s[i+1] == 'A') num = 1;
            else if (s[i+1] == 'J') num = 11;
            else if (s[i+1] == 'Q') num = 12;
            else if (s[i+1] == 'K') num = 13;
            else if (s[i+1] == '1') {
                num = 10;
            }
            royalcand[suit][max(num - 9, 0)] = v.size();
        }
        if (s[i+1] == '1') {
            v.push_back(s.substr(i, 3));
            i++;
        } else {
            v.push_back(s.substr(i, 2));
        }

        bool ok = true;
        for (int j = 0; j < 4; ++j) {
            ok = true;
            for (int k = 0; k < 5; ++k) {
                if (royalcand[j][k] < 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int k = 0; k < 5; ++k) {
                    take.push_back(royalcand[j][k]);
                }
                break;
            }
        }
        if (ok) break;
    }
    for (int i = 0; i < v.size(); ++i) {
        if (find(take.begin(), take.end(), i) != take.end()) continue;
        cout << v[i];
    }
    if (v.size() == 5) {
        cout << 0;
    }
    cout << endl;
}
