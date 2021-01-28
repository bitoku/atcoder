#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < 1000; ++i) {
        int k = 0;
        bool find = false;
        for (char j : s) {
            if (k == 0 and j - '0' == i / 100) {
                k++;
            } else if (k == 1 and j - '0' == i / 10 % 10) {
                k++;
            } else if (k == 2 and j - '0' == i % 10) {
                find = true;
            } 
        }
        if (find) {
            cnt++;
        }
    }
    cout << cnt << endl;
}
