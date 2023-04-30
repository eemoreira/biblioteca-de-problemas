#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int mx;
  cin >> mx;
  n -= 1;
  bool ok = true;
  while (n--) {
    int a;
    cin >> a;
    if (a > mx) {
      ok = false;
    }
  }
  cout << (ok ? "S\n" : "N\n");
}
