#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    int white_cnt = 0;
    ll result = 0;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'W') {
            result += i - white_cnt;
            white_cnt++;
        }
    }
    cout << result << endl;
}
