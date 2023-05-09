#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t = s.back() - 'A' + 1;
    cout << (n & 1 && (n + 1) / 2 == t ? "S\n" : "N\n");
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

