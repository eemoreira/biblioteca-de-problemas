#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    int ans = -1;
    for (int i = n; i <= m; i++) {
        int t = i;
        int now = 0;
        while (t > 0) {
            now = now + (t % 10);
            t = t / 10;
        }
        if (now == s) {
            ans = i;
        }
    }
    cout << ans << '\n';
}





