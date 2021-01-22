#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a, b;
    char before = 'x';
    int cnt = 0;
    int score = 0;
    for (const auto& c : s) {
        if (before == 'x') {
            before = c;
            continue;
        }
        if (before == c) {
            score++;
            continue;
        }
        before = c;
        cnt++;
    }
    for (int i = 0; i < k; ++i) {
        if (cnt == 0) break;
        if (cnt > 1) {
            score += 2;
            cnt -= 2;
        }
        else if (cnt == 1) {
            score += 1;
            cnt -= 1;
        }
    }
    cout << score << endl;
}
