#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

bool vog(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    int v = 0;
    for (char u : s) {
        if (vog(u)) {
            v++;
        }
    }
    if (!v) {
        cout << 1 << '\n';
        return 0;
    }
    if (!vog(s[0])) {
        cout << 0 << '\n';
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += vog(s[i]);
        if (cnt == (v + 1) / 2) {
            int ans = i != n - 1;
            int y = i + 1;
            while (y < n && !vog(s[y])) {
                ans++;
                y++;
            }
            cout << ans << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
}






