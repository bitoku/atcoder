#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int n;
char alpha[12] = "abcdefghijk";

//char maxchar(const string& s) {
//    char ans = 'a';
//    for (int i = 0; i < s.size() - 1; ++i) {
//        ans = max(ans, s[i]);
//    }
//    return ans;
//}
//
//int main() {
//    cin >> n;
//    string s(n, 'a');
//    if (n == 1) {
//        cout << s << endl;
//        return 0;
//    }
//    while (s.front() == 'a') {
//        cout << s << endl;
//        while (s.back() <= maxchar(s)) {
//            char c = s.back();
//            s.pop_back();
//            s.push_back(c + 1);
//            cout << s << endl;
//        }
//        while (s.back() > maxchar(s)) {
//            s.pop_back();
//        }
//        char c = s.back();
//        s.pop_back();
//        s.push_back(c + 1);
//        while (s.size() < n) {
//            s.push_back('a');
//        }
//    }
//}

void dfs(string s, char mx) {
    if (s.size() == n) {
        cout << s << endl;
    } else {
        for (char i = 'a'; i <= mx; ++i) {
            dfs(s + i, (i == mx) ? mx + 1 : mx);
        }
    }
}

int main() {
    cin >> n;
    dfs("", 'a');
}