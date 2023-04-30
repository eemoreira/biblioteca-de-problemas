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
    ll n,m; cin >> n >> m;
    ll a = n*m;
    int t = n;
    int two = 0;
    int five = 0;
    while(t%2==0) two++, t>>=1;
    t = n;
    while(t%5==0) five++, t /= 5;
    ll ans = 1;
    int r = abs(five-two);
    int f = (five > two ? 2 : 5);
    while(r && ans*f <= m) ans *= f,r--;
    while(10*ans <= m) ans *= 10;
    ans *= n;
    ans = ans*(m*n/ans);
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


