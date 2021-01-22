#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ctoi(char c) {
    return c - '0';
}

int main() {
    string s;
    int cnt[10] = {};
    cin >> s;
    for (const auto c : s) {
        cnt[ctoi(c)]++;
    }
    if (s.size() == 1) {
        if (ctoi(s[0]) % 8 == 0) {
            cout << "Yes" << endl;
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    if (s.size() == 2) {
        if ((ctoi(s[0]) * 10 + ctoi(s[1])) % 8 == 0 || (ctoi(s[1]) * 10 + ctoi(s[0])) % 8 == 0) {
            cout << "Yes" << endl;
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            for (int k = 1; k < 10; ++k) {
                if ((4 * i + 2 * j + 1 * k) % 8 == 0) {
                    cnt[i]--;
                    cnt[j]--;
                    cnt[k]--;
                    if (cnt[i] >= 0 && cnt[j] >= 0 && cnt[k] >= 0) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                    cnt[i]++;
                    cnt[j]++;
                    cnt[k]++;
                }
            }
        }
    }
    cout << "No" << endl;
}
