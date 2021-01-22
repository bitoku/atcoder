#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(const string& ss) {
    if (ss.size() % 2 != 0) return false;
    int size = (int)ss.size() / 2;
    for (int i = 0; i < size; ++i) {
        if (ss[i] != ss[size + i]) return false;
    }
    return true;
}

int main() {
    string ss;
    cin >> ss;
    ss.pop_back();
    while (!check(ss)) {
        ss.pop_back();
    }
    cout << ss.size() << endl;
}
