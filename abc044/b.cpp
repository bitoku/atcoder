#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int alpha[26] = {};
    string w;
    cin >> w;
    for (int i = 0; i < w.size(); ++i) {
        alpha[w[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (alpha[i] % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
