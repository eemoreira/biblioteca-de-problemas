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
    ll l,r,x; cin >> l >> r >> x;
    ll a,b; cin >> a >> b;
    if(a == b) cout << 0 << '\n';
    else if(abs(a-b) >= x) cout << 1 << '\n';
    else{
        int ans = 1e9;
        if(abs(r-a) >= x){
            if(abs(b-r) >= x){
                ans = min(ans,2);
            }
            else if(abs(l-b) >= x){
                ans = min(ans,3);
            }
        }
        if(abs(l-a) >= x){
            if(abs(b-l) >= x){
                ans = min(ans,2);
            }
            else if(abs(r-b) >= x){
                ans = min(ans,3);
            }
        }
        cout << (ans == 1e9 ? -1 : ans) << '\n';
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


