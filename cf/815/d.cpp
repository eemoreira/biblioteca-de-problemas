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
const int mx = 3e5 + 5;
int dp[mx];
int a[mx];
int n; 

int go(int f){
    if(f >= n) return 0;
    if(dp[f] != -1) return dp[f];
    int ans = 0;
    for(int i = f+1; i <= f + 401; i++){
        if(i >= n) break;
        if((a[f]^i) < (a[i]^f)){
            int t = go(i);
            ans = max(ans, t + 1);
        }
    }
    return dp[f] = ans;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
        dp[i] = -1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans,go(i));
    }
    cout << ans + 1 << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


