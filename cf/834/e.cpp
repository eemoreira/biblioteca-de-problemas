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
    int n; ll h; cin >> n >> h;
    vll a(n);
    for(auto &u : a) cin >> u;
    sor(a);
    vll m = {2ll ,2ll ,3ll};
    int t = h;
    int ans = 0;
    do{
        int cnt = 0;
        h = t;
        for(auto u : m){
            for(int i = cnt; i < n; i++) if(a[i] < h) h += a[i]/2,cnt++;
            h *= u;
        }
        for(int i = cnt; i < n; i++) if(a[i] < h) h += a[i]/2,cnt++;
        ans = max(ans,cnt);
    }while(next_permutation(all(m)));
    cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


