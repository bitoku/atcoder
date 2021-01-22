#include <iostream>

using namespace std;

int main() {
    unsigned long long a;
    string b;
    cin >> a >> b;
    cout << (a * (b[0]-'0') * 100 + a * (b[2]-'0') * 10 + a * (b[3]-'0')) / 100 << endl;
    return 0;
}