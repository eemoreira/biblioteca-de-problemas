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
const int mx = 2e5 + 5;

void solve(){
    int n; cin >> n;
    vll a(n);
    for(auto &u : a) cin >> u;
    ll dif = 0;
    ll ans = 0;
    ll s = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1]) continue;
        if(a[i] > a[i-1]){
            dif += (a[i] - dif - a[i-1]);
            s += dif;
            ans += (a[i] - a[i-1]);
        }
        else{
            ans += (a[i-1] - a[i]);
        }
        /* cout << "ans: " << ans << " dif: " << dif << '\n'; */
    }
    /* cout << "dif: " << dif << '\n'; */
    cout << ans + abs(a[n-1] - s) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


