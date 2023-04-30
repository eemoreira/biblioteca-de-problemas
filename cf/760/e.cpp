#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  long long n;
  cin >> n;
  long long sum = 0;
  vector<long long> a(n);
  for (auto &u : a) {
    cin >> u;
    sum += u;
  }
  long long all = n * (n+1) / 2;
  if (sum%all) {
    cout << "no\n";
    return;
  }
  sum /= all;
  dbg(sum);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    long long now = a[(i-1+n)%n] - a[i];
    now += sum;
    dbg(i, now);
    if (now <= 0 || now%n) {
      cout << "no\n";
      return;
    }
    now /= n;
    ans[i] = now;
  }
  cout << "yes\n";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i+1 == n];
  }
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





