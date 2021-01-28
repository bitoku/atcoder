#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    deque<char> dq;
    int cnt = 0;
    for (const auto c: s) {
        if (c == '(') {
            cnt++;
        } else if (cnt <= 0) {
            dq.push_front('(');
        } else {
            cnt--;
        }
        dq.push_back(c);
    }
    while (cnt > 0) {
        dq.push_back(')');
        cnt--;
    }
    for (const auto c: dq) {
        cout << c;
    }
    cout << endl;
}
