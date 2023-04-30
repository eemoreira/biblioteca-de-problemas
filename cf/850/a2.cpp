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
  int a2 = 0;
  int b = 0;
  int b2 = 0;
  int num = 0;
  while (n) {
    if (cnt&1) {
      if (num  <= n) {
        b2 += num / 2;
        b += num / 2;
        n -= num;
      }
      else {
        b2 += (n+1)/ 2;
        b += n / 2;
        n = 0;
        break;
      }
      num++;
      if ( num <= n) {
        b2 += num /2 + 1;
        b += num /2;
        n -= num;
      }
      else {
        b2 += (n+1)/2;
        b += n/2;
        n = 0;
        break;
      }
    }
    else {
      if (num  <= n) {
        a += num / 2;
        a2 += num / 2;
        n -= num;
      }
      else {
        a += (n+1)/ 2;
        a2 += n / 2;
        n = 0;
        break;
      }
      num++;
      if ( num <= n) {
        a += num /2 + 1;
        a2 += num /2;
        n -= num;
      }
      else {
        a += (n+1)/2;
        a2 += n/2;
        n = 0;
        break;
      }
    }
    num++;
    cnt++;
  }
  dbg(n);
  cout << a << ' ' << a2 << ' ' << b << ' ' << b2 << '\n';
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






