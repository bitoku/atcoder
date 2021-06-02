#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

bool isCamel(string& s) {
    if (!('a' <= s[0] && s[0] <= 'z')) {
        return false;
    }
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '_') return false;
    }
    return true;
}

string splitCamel(string& s) {
    vector<string> v;
    v.emplace_back("");
    for (int i = 0; i < s.size(); ++i) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            v.emplace_back("");
            v.back().push_back(s[i] - 'A' + 'a');
        } else {
            v.back().push_back(s[i]);
        }
    }
    string t = v[0];
    for (int i = 1; i < v.size(); ++i) {
        t.push_back('_');
        t += v[i];
    }
    return t;
}

bool isSnake(string &s) {
    if (!('a' <= s[0] && s[0] <= 'z')) {
        return false;
    }
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '_') {
            i++;
            if (s[i] == '_') return false;
            if ('A' <= s[i] && s[i] <= 'Z') return false;
            if ('0' <= s[i] && s[i] <= '9') return false;
        }
        if ('A' <= s[i] && s[i] <= 'Z') return false;
    }
    return true;
}

string splitSnake(string &s) {
    string t;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '_') {
            i++;
            t.push_back(s[i] - 'a' + 'A');
        } else {
            t.push_back(s[i]);
        }
    }
    return t;
}

int main() {
    string s;
    cin >> s;
    string front;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '_') front.push_back('_');
        else break;
    }
    if (front.size() == s.size()) {
        cout << front << endl;
        return 0;
    }
    string back;
    for (int i = s.size()-1; i >= front.size(); --i) {
        if (s[i] == '_') back.push_back('_');
        else break;
    }
    string t = s.substr(front.size(), s.size() - front.size() - back.size());
    if (isCamel(t)) {
        cout << front << splitCamel(t) << back << endl;
    } else if (isSnake(t)) {
        cout << front << splitSnake(t) << back << endl;
    } else {
        cout << s << endl;
    }

}