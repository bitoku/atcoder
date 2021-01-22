#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    string ss;
    string atgc = "ATGC";
    int m = 0;
    for (const auto& c : s) {
        auto pos = atgc.find(c);
        if (pos != string::npos) {
            ss += c;
        } else {
            ss.clear();
        }
        m = max(m, (int)ss.size());
    }
    cout << m << endl;
}
