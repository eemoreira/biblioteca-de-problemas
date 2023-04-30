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
  string s;
  cin >> n >> s;
  int ptr = 0;
  int ok = 0;
  while (ptr < n && (s[ptr] == 'M' || s[ptr] == 'm')) {
    ok = 1;
    ptr++;
  }
  while (ptr < n && (s[ptr] == 'e' || s[ptr] == 'E')) {
    if (ok == 1) ok = 2;
    ptr++;
  }
  while (ptr < n && (s[ptr] == 'o' || s[ptr] == 'O')) {
    if (ok == 2) ok = 3;
    ptr++;
  }
  while (ptr < n && (s[ptr] == 'w' || s[ptr] == 'W')) {
    if (ok == 3) ok = 4;
    ptr++;
  }
  dbg(ok);
  cout << (ptr == n && ok == 4 ? "yes\n" : "no\n");
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





