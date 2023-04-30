#include <bits/stdc++.h>

using namespace std;

/* stop freaking out pls */
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string v = "aeiou";
    int n = s.size();
    string l = "", r = "";
    for (int i = 0; i < n; i++) {
        for (auto u : v) {
            if (s[i] == u) {
                l += s[i];
            }
            if (s[n-i-1] == u) {
                r += s[n-i-1];
            }
        }
    }
    cout << (l == r ? "S\n" : "N\n");
}





