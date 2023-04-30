#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a != b && a != c) {
        cout << "A\n";
    }
    else if (b != a && b != c) {
        cout << "B\n";
    }
    else if (c != a && c != b) {
        cout << "C\n";
    }
    else {
        cout << "*\n";
    }
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}
