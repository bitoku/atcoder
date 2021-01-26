#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int> black(n+1);
    vector<int> white(n+1);
    for (int i = 1; i <= n; ++i) {
        black[i] = black[i-1];
        white[i] = white[i-1];
        if (s[i-1] == '.') white[i]++;
        else black[i]++;
    }
    int result = 1000000;
    for (int i = 0; i <= n; ++i) {
        int left_black = black[i];
        int right_white = white[n] - white[i];
        result = min(result, left_black + right_white);
    }
    cout << result << endl;
}
