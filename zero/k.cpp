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
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1') {
      if (n <= 45) {
        cout << n << '\n';
      }
      else {
        cout << "45+" << n - 45 << '\n';
      }
    }
    else {
      if (n <= 45) {
        cout << n+45 << '\n';
      }
      else {
        cout << "90+" <<  n - 45 << '\n';
      }
    }
  }
  cout << '\n';
}





