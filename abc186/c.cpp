#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll result = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> decimal;
        vector<int> octal;
        int t = i;
        while (t > 0) {
            decimal.push_back(t % 10);
            t /= 10;
        }
        t = i;
        while (t > 0) {
            octal.push_back(t % 8);
            t /= 8;
        }
        if (all_of(decimal.begin(), decimal.end(), [](int x) {return x != 7;}) &&
            all_of(octal.begin(), octal.end(), [](int x) {return x != 7;})) {
            result++;
        }
    }
    cout << result << endl;
}
