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
  int cnt = 0;
  int a = 0;
  int b = 0;
  int num = 0;
  while (n) {
    if (cnt&1) {
      if (num  <= n) {
        b += num;
        n -= num;
      }
      else {
        b += n;
        n = 0;
        break;
      }
      num++;
      if ( num <= n) {
        b += num;
        n -= num;
      }
      else {
        b += n;
        n = 0;
        break;
      }
    }
    else {
      if (num <= n) {
        a += num;
        n -= num;
      }
      else {
        a += n;
        n = 0;
        break;
      }
      num++;
      if (num <= n) {
        n -= num;
        a += num;
      }
      else {
        a += n;
        n = 0;
        break;
      }
    }
    num++;
    cnt++;
  }
  dbg(n);
  cout << a << ' ' << b << '\n';
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





