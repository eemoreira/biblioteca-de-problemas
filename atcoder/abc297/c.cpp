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

/* stop freaking out pls */
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> ans(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m - 1; j++) {
            if (s[j] == 'T' && s[j + 1] == 'T') {
                s[j] = 'P';
                s[j + 1] = 'C';
            }
        }
        ans[i] = s;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}





