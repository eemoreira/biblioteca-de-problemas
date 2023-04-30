#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqmin;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back
#define inf 1e9+5
#define linf 1e17+5

int ok2321 = 1;

void solve(){
  int n; cin >> n;
  vi a(n);
  for(auto &u : a) cin >> u;
  sor(a);
  bool ok = true;
  for(int i = 1; i < n; i++){
    ok &= (a[i-1] == a[i]);
  }
  if(ok) cout << n/2 << '\n';
  else{
    int median = a[n/2];
    int am = 0, am2 = 0;
    for(int i = 0; i < n; i++) if(a[i] <= median) am++;
    for(int i = 0; i < n; i++) if(a[i] < median) am2++;
    cout << max((ll) am2 * (n - am2), (ll) am * (n - am)) << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



