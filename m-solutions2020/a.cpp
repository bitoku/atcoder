#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int kyu;
    if (400 <= n && n <= 599) kyu=8;
    else if (600 <= n && n <= 799) kyu=7;
    else if (800 <= n && n <= 999) kyu=6;
    else if (1000 <= n && n <= 1199) kyu=5;
    else if (1200 <= n && n <= 1399) kyu=4;
    else if (1400 <= n && n <= 1599) kyu=3;
    else if (1600 <= n && n <= 1799) kyu=2;
    else if (1800 <= n && n <= 1999) kyu=1;
    cout << kyu << endl;
}
