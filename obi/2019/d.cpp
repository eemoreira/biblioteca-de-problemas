#include <bits/stdc++.h>

using namespace std;
using i3 = tuple<int,int,int>;
using i64 = long long;
using ii = pair<int,int>;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int maxn = 505;
int n, m;
string a[maxn];

bool valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.';
}

void dfs(int i, int j) {
  a[i][j] = 'o';
  if (valid(i + 1, j)) {
    dfs(i + 1, j);
  }
  else if (i < n - 1 && a[i + 1][j] == '#') {
    if (valid(i, j + 1)) {
        dfs(i, j + 1);
    }
    if (valid(i, j - 1)) {
      dfs(i, j - 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  ii s = {1e9,1e9};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'o') {
        s = ii(i, j);
      }
    }
  }
  dfs(s.first, s.second);
  cout << '\n';
  for (int i = 0; i < n; i++) {
    cout << a[i] << '\n';
  }
}





