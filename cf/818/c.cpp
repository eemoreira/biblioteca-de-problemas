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
  vi a(n), b(n);
  for(auto &u : a) cin >> u;
  for(auto &u : b) cin >> u;
  bool dr = false;
  for(int i = 0; i < n; i++) if(a[i]>b[i]) dr = true;
  if(dr){
    cout << "NO\n";
    return;
  }
  b.pb(b[0]);
  a.pb(a[0]);
  for(int i = 1; i <= n; i++){
    if(b[i] < b[i-1] - 1 && a[i-1] != b[i-1]){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



