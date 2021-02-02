#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    vector<int> continuous;
    char before = '1';
    continuous.push_back(0);
    for (char c : s) {
        if (c != before) {
            continuous.push_back(1);
            before = c;
        } else {
            continuous[continuous.size()-1]++;
        }
    }
    if (continuous.size() <= 2) {
        cout << n << endl;
        return 0;
    }
    if (s[s.size() - 1] == '0') {
        continuous.push_back(0);
    }
    int sum = continuous[0];
    for (int i = 1; i < 2 * k; i += 2) {
        sum += continuous[i] + continuous[i + 1];
    }
    int m = sum;
    for (int i = 2 * k + 1; i < continuous.size(); i += 2) {
        sum -= continuous[i - (2 * k + 1)] + continuous[i - 2 * k];
        sum += continuous[i] + continuous[i + 1];
        m = max(m, sum);
    }
    cout << m << endl;
}
