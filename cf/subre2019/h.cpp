#include<bits/stdc++.h>
using namespace std;

int main() {
  long long n, v;
  cin >> n >> v;
  v *= n;
  for (int i = 1; i <= 9; i++) {
    long long now = v * i;
    cout << now / 10 + (now % 10 > 0) << ' ';
  }
  cout << '\n';
}
