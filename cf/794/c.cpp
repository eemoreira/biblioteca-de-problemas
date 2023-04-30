#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  if (n&1) {
    cout << "no\n";
    return;
  }
  vector<int> ans(n);
  sort(a.begin(), a.end());
  bool ok = true;
  int ptr = n-1;
  if (a[ptr] < a[n/2-1]) {
    ok = false;
  }
  ans[0] = a[ptr--];
  int f = n/2-1;
  assert(f >= 1);
  ans[1] = a[f--];
  ans[n-1] = a[f--];
  int l = 2, r = n-2;
  dbg(l,r);
  while (l <= r) {
    if (l == r) {
      if (a[ptr] > ans[l-1] && a[ptr] > ans[r+1]) {
        ans[l] = a[ptr];
      }
      else {
        ok = false;
      }
    }
    else {
      dbg(ptr,l,r,f);
      if (a[ptr] > ans[l-1] && a[ptr] > a[f]) {
        ans[l] = a[ptr--];
        ans[l+1] = a[f--];
      }
      else {
        ok = false;
        break;
      }
      if (a[ptr] > ans[r+1]) {
        if (f >= 0) {
          if (a[ptr] > a[f]) {
            ans[r] = a[ptr--];
            ans[r-1] = a[f--];
          }
          else {
            ok = false;
            break;
          }
        }
        else if (a[ptr] > ans[r-1]) {
          ans[r] = a[ptr--];
        }
      }
      else {
        ok = false;
        break;
      }
    }
    l+=2;
    r-=2;
  }
  dbg(ans);
  if (!ok) {
    cout << "no\n";
    return;
  }
  cout << "yes\n";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n-1];
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





