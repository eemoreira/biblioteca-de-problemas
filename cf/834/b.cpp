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
    int m,s; cin >> m >> s;
    vi a(m);
    for(auto &u : a) cin >> u;
    map<int,int> f;
    int ma = -1e9;
    for(auto u : a) f[u]++, ma = max(u,ma);
    int sum = 0;
    int cnt = 0;
    for(int i = 1; i <= 1000; i++){
        if(!f[i])sum += i, cnt++;
        if(sum > s) break;
        if(s==sum && i >= ma && cnt){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


