#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "codes/debug.h"
#else
#define dbg(...)
#endif

/* stop freaking out pls */
void solve() {

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  for (cin >> n; n; cin >> n) {
    long long ans = 0;
    while (n) {
      ans += n*n;
      n--;
    }
    cout << ans << '\n';
  }
}




