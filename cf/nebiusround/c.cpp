#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    long long n,x,p;
    cin >> n >> x >> p;
    long long all = n * (n - 1) / 2;
    int y = all % n;
    int cnt = 0;
    for (int i = 0; ; i++) {
        long long now = all * i;
        int t = i ? 0 : 1;
        for (int j = i ? 0 : 1; j < n; j++) {
            now += j;
            cnt = n * i + t;
            t += 1;
            if (cnt > p) {
                break;
            }
            if (now % n == (n - x) % n) {
                cout << "yes\n";
                return;
            }
        }
        now = all * i;
        if (i > 1 && now % n == y) {
            break;
        }
    }
    cout << "no\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





