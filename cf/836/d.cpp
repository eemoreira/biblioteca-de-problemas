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
  if(!(n&1)){
    for(int i = n/2; i <= n + n/2; i++) if(i != n) cout << i << ' ';
    cout << '\n';
  }
  else{
    vi ans(n);
    for(int i = 0; i < n; i++) ans[i] = (n+1)/2 + i + 2;
    ans[0]--;
    ans[n-1]++;
    ans[n-2]++;
    for(auto u : ans) cout << u << ' ';
    cout << '\n';
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



