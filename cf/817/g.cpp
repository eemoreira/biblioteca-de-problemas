#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 1;

void solve(){
    int n; cin >> n;
    int c = 0;
    int xo=0,xe=0;
    vi ans[200005];
    for(int i = 1  + c; i < n-1 + c; i++){
        if((i+c)&1)xo ^= i;
        else xe ^= i;
        ans[c].pb(i);
        if(i == n-2+c && xe == xo){
            xe = xo = 0;
            c++;
            i = 1;
        }
    }
    if(n&1){
        ans[c].pb(xo + (1 << 30));
        ans[c].pb(xe + (1 << 30));
    }
    else{
        ans[c].pb(xe + (1 << 30));
        ans[c].pb(xo + (1 << 30));
    }
    int x = 0;
    for(auto u : ans[c]){
        cout << u << ' ';
        x ^= u;
    }
    cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


