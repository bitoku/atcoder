#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

vector<string> tokenize(const string& s) {
    vector<string> result;
    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '{' || s[i] == '}' || s[i] == ':' || s[i] == ',') {
            if (start < i) {
                result.emplace_back(s.substr(start, i-start));
                start = i;
            }
            result.emplace_back(s.substr(start, 1));
            start = i+1;
        }
    }
    return result;
}

template<class T>
void printVector(vector<T> &a) {
    if (a.size() == 0) return;
    cout << a[0];
    for (int i = 1; i < a.size(); ++i) {
        cout << " " << a[i];
    }
    cout << endl;
}

int main() {
    string s;
    cin >> s;
    vector<string> tokens = tokenize(s);
    if (s == "{}") {
        cout << "dict" << endl;
        return 0;
    }
    int brace = 0;
    for (int i = 1; i < tokens.size(); ++i) {
        if (brace == 0) {
            if (tokens[i] == "{") {
                brace++;
                continue;
            }
            if (tokens[i] == ":") {
                cout << "dict" << endl;
                return 0;
            } else if (tokens[i] == "," || tokens[i] == "}") {
                cout << "set" << endl;
                return 0;
            }
        } else {
            if (tokens[i] == "{") {
                brace++;
            } else if (tokens[i] == "}") {
                brace--;
            }
        }
    }
}
