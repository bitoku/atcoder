#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int k;
    cin >> k;
    cin >> s;
    if (s.size() <= k) {
        cout << s << endl;
    } else {
        cout << s.substr(0, k) << "..." << endl;
    }
    return 0;
}
