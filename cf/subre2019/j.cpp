#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(14));
  map<char,int> ch;
  ch['A'] = 1;
  for (int i = 2; i <= 9; i++) {
    ch['0' + i] = i;
  }
  ch['D'] = 10;
  ch['Q'] = 11;
  ch['J'] = 12;
  ch['K'] = 13;
  int f = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto u : s) {
      a[i][ch[u]] += 1;
      if (a[i][ch[u]] == 4 && !f && f != k) {
        f = i + 1;
      }
    }
  }
  if (f && f != k) {
    cout << f << '\n';
    return 0;
  }
  k -= 1;
  bool wait = 0;
  vector<int> has(n, 0);
  has[k] = 1;
  int ptr = k;
  while (true) {
    bool can = (wait && has[ptr]) || !has[ptr];
    for (auto u : a[ptr]) {
      if (u == 4 && can) {
        cout << ptr + 1 << '\n';
        return 0;
      }
    }
    if (wait && has[ptr]) {
      has[ptr] = 0;
      ptr += 1;
      ptr %= n;
      has[ptr] = 1;
      wait = false;
      continue;
    }
    if (!wait && has[ptr]) {
      wait = true;
    }
    pair<int,int> now = {1e9,1e9};
    for (int i = 1; i <= 13; i++) {
      if (a[ptr][i] > 0) {
        now = min(now, make_pair(a[ptr][i], i));
      }
    }
    a[ptr][now.second] -= 1;
    ptr += 1;
    ptr %= n;
    a[ptr][now.second] += 1;
  }
  assert(false);
}





