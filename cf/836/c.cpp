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
  int n,x; cin >> n >> x;
  vi ans(n+1);
  ans[1] = x;
  for(int i = 2; i < n; i++){
    ans[i] = i;
  }
  if(n%x){
    cout << -1 << '\n';
    return;
  }
  vi f;
  int d = 2;
  int want = n/x;
  while(want){
    if(d*d > n/x) break;
    if(want%d==0){
      f.pb(d);
      want /= d;
    }
    else d++;
  }
  if(want > 1) f.pb(want);
  cout << x << ' ';
  want = x;
  sor(f);
  for(int i = 0; i < (int)f.size(); i++){
    ans[want] = f[i]*want;
    want *= f[i];
  }
  for(int i = 2; i < n; i++) cout << ans[i] << ' ';
  cout << 1 << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}




