#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int alpha[101][26] = {0};
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            alpha[i+1][j] = alpha[i][j];
        }
        alpha[i+1][s[i]-'a']++;
    }
    int result = 0;
    for (int i = 1; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < 26; ++j) {
            if (alpha[n][j] - alpha[i][j] > 0 && alpha[i][j] > 0) {
                cnt++;
            }
        }
        result = max(result, cnt);
    }
    cout << result << endl;
}
