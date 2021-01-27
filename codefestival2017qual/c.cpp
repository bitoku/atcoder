#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    string swox;
    cin >> s;
    int left = 0;
    int right = s.size() - 1;
    int cnt = 0;
    while (left < right) {
        if (s[left] == s[right]) {
            left++; right--;
            continue;
        }
        if (s[left] == 'x') {
            cnt++;
            left++;
        } else if (s[right] == 'x') {
            cnt++;
            right--;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
}
