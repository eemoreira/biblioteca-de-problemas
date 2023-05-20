#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

// foskapo
// poaskfofk

int go(int i, int j, string& s, string& word, vector<vector<int>>& dp) {
  int maxi = s.size();
  int maxj = word.size();
  if (i == maxi) return maxj - j;
  if (j == maxj) return maxi - i;
  if (dp[i][j] != 1e9) return dp[i][j];
  int x = go(i, j + 1, s, word, dp) + 1;
  int y = go(i + 1, j + 1, s, word, dp) + (s[i] != word[j]);
  int z = go(i + 1, j, s, word, dp) + 1;
  return dp[i][j] = min({x, y, z});
}

int solve(string& s, string& word) {
  vector<vector<int>> dp((int)s.size(), vector<int>((int)word.size(), 1e9));
  dbg(s, word);
  return go(0, 0, s, word, dp);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  vector<int> ans(5);
  while (tt--) {
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> cost(5);
    for (int i = 0; i < 5; i++) {
      string now;
      cin >> now;
      cost[i] += solve(s, now);
    }
    int mincost = *min_element(cost.begin(), cost.end());
    for (int i = 0; i < 5; i++) {
      if (cost[i] == mincost) {
        ans[i] += 1 + !mincost;
      }
    }
  }
  int mx = *max_element(ans.begin(), ans.end());
  cout << mx / 2;
  if (mx & 1) cout << ".5\n";
  else cout << ".0\n";
  vector<int> a;
  for (int i = 0; i < 5; i++) {
    if (ans[i] == mx) {
      a.emplace_back(i + 1);
    }
  }
  int n = a.size();
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
}





