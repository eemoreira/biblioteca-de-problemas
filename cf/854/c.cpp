#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
string s;

string solve(char mx) {
  int n = s.size();
  multiset<char> pq;
  for (int i = 0; i < n; i++) {
    if (s[i] >= mx) {
      pq.emplace(s[i]);
    }
  }
  string back = "", front = "";
  while ((int)pq.size() > 1) {
    char f = *pq.begin();
    pq.erase(pq.begin());
    char h = *pq.begin();
    pq.erase(pq.begin());
    front += h;
    back += f;
    if (h != f) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] < mx) {
      pq.emplace(s[i]);
    }
  }
  reverse(back.begin(), back.end());
  while (!pq.empty()) {
    front += *pq.begin();
    pq.erase(pq.begin());
  }
  front += back;
  string t = front;
  reverse(t.begin(), t.end());
  return max(t,front);
}

void solve() {
  cin >> s;
  int n = s.size();
  vector<int> f(26);
  for (int i = 0; i < n; i++) {
    f[s[i]-'a'] += 1;
  }
  string front = "", back = "";
  s = "";
  for (int i = 0; i < 26; i++) {
    while (f[i] > 1) {
      f[i] -= 2;
      front += char(i + 'a');
      back += char(i + 'a');
    }
    if (f[i] == 1) {
      break;
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < f[i]; j++) {
      s += char(i + 'a');
    }
  }
  reverse(back.begin(), back.end());
  string ans(n, 'z');
  for (int i = 0; i < 26; i++) {
    ans = min(ans, solve(char(i+'a')));
  }
  front += ans + back;
  cout << front << '\n';
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





