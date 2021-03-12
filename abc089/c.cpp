#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll initial[5] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s[0] == 'M') initial[0]++;
        else if (s[0] == 'A') initial[1]++;
        else if (s[0] == 'R') initial[2]++;
        else if (s[0] == 'C') initial[3]++;
        else if (s[0] == 'H') initial[4]++;
    }
    ll result = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = i+1; j < 5; ++j) {
            for (int k = j+1; k < 5; ++k) {
                result += initial[i] * initial[j] * initial[k];
            }
        }
    }
    cout << result << endl;
}
