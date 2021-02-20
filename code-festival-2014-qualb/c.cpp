#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int c1[26]={0}, c2[26]={0}, c3[26]={0};
    for (const auto c : s1) {
        c1[c - 'A']++;
    }
    for (const auto c : s2) {
        c2[c - 'A']++;
    }
    for (const auto c : s3) {
        c3[c - 'A']++;
    }
    int n = (int)s1.size();
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < 26; ++i) {
        if (c1[i] >= c3[i] && c2[i] >= c3[i]) continue;
        else if (c1[i] >= c3[i] && c2[i] < c3[i]) {
            int diff = c3[i] - c2[i];
            c1[i] -= diff;
            cnt1 += diff;
            c3[i] -= diff;
        }
        else if (c1[i] < c3[i] && c2[i] >= c3[i]) {
            int diff = c3[i] - c1[i];
            c2[i] -= diff;
            cnt2 += diff;
            c3[i] -= diff;
        }
        else if (c1[i] + c2[i] < c3[i]) {
            cout << "NO" << endl;
            return 0;
        } else {
            int c = max(c1[i], c2[i]);
            int diff = c3[i] - c;
            c3[i] -= diff * 2;
            c1[i] -= diff;
            cnt1 += diff;
            c2[i] -= diff;
            cnt2 += diff;
            i--;
            continue;
        }
    }
    if (cnt1 > n / 2 || cnt2 > n / 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
