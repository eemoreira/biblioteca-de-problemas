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
const int mx = 3e3 + 5;
const int inf = 1e9 + 5;
int dp[mx][mx];
string s;

int go(int l, int r){
    if(l - r == 1) return dp[l][r] = (s[l] == s[r]);
    if(dp[l][r] != -1) return dp[l][r];
    int ok = 1;
    ok &= ((s[l] == s[l+1] && go(l+2,r)) && (s[r] == s[r-1] && go(l,r-2)));
    ok |= (s[l] == s[r] && go(l+1,r-1));
    return dp[l][r] = (int) ok;
}

void solve(){
    cin >> s;
    int n = (int)s.size();
    for(int i = 0; i <= n; i++){
        for(int k = 0; k <= n; k++){
            dp[i][k] = -1;
        }
    }
    cout << (go(0,n-1) ? "Draw\n" : "Alice\n");
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


