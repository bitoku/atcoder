#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

string dfs(string& s, int& p) {
    if (isdigit(s[p])) {
        int q = p;
        while (isdigit(s[p])) {
            p++;
        }
        return s.substr(q, p - q);
    }
    if (s[p] == '+' || s[p] == '*' || s[p] == '-' || s[p] == '/') {
        char ope = s[p];
        p++;
        string t = "(";
        while (s[p] != ')') {
            p++;
            t += dfs(s, p);
            t.push_back(ope);
        }
        t.pop_back();
        t.push_back(')');
        p++;
        return t;
    }
    if (s[p] == '(') {
        p++;
        string t = "(" + dfs(s, p) + ")";
        p++;
        return t;
    }
}

int main() {
    string s;
    cin >> s;
    int p = 0;
    cout << dfs(s, p) << endl;
}