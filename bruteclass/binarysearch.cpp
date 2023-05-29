#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x;
  cin >> x;
  int l = 0, r = n - 1;
  // intervalo tem tamanho n
  int resposta = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] <= x) {
      l = mid + 1;
      resposta = mid;
    }
    else {
      r = mid - 1;
    }
  }
  if (resposta == -1) {
    cout << -1 << '\n';
  }
  else {
    cout << a[resposta] << '\n';
  }
}





