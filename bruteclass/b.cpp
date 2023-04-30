#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> f;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        f[s]++;
    }
    string s;
    cin >> s;
    cout << f[s] << '\n';
}
