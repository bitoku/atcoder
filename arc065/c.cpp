#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    string candidate[4] = {
        "dreamer",
        "dream",
        "eraser",
        "erase",
    };
    cin >> s;
    int s_size = s.size();
    while(s_size > 0) {
        bool creatable = false;
        for (auto & word : candidate) {
            bool included = true;
            for (int k = 0; k < word.size(); ++k) {
                if (s_size < word.size() || word[k] != s[s_size - word.size() + k]) {
                    included = false;
                    break;
                }
            }
            if (included) {
                s_size -= word.size();
                creatable = true;
            }
        }
        if (!creatable) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
