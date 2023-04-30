#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve(string &t) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < (int)t.size()-n; i++) {
    string now = t.substr(i,n);
    if (s == now) {
      cout << "yes\n";
      return;
    }
  }
  cout << "no\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  string t = "";
  for (int i = 0; i < 500; i++) {
    if (i%3 == 0) {
      t += 'F';
    }
    if (i%5 == 0) {
      t += 'B';
    }
  }
  while (tt--) {
    solve(t);
  }
}





