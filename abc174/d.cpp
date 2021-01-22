#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int r = 0;
    int w = 0;
    for (char i : s) {
        if (i == 'R') r++;
        else w++;
    }
    int bad_stone = 0;
    for (int i = 0; i < r; ++i) {
        if (s[i] == 'W') bad_stone++;
    }
    cout << bad_stone << endl;
}
