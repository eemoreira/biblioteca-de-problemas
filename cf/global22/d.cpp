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
const int mx = 1e5 + 5;
int n;
vi adj[mx];

void bfs(int v){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        sort(all(adj[cur]), [&](int a, int b ){ return (int)adj[a].size() < (int)adj[b].size();});
        for(auto u : adj[cur]){
            q.push(u);
        }
        if(cur != 0 && cur != n+1) cout << cur << " \n"[q.empty()];
    }
}

void solve(){
    cin >> n;
    vi b(n+1);
    int k = 0;
    for(int i = 0; i <= n+1; i++) adj[i].clear();
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        if(i < b[i]) k = i;
    }
    cout << k << '\n';
    for(int i = 1; i <= n; i++){
        adj[b[i]].pb(i);
    }
    int root = ((int)adj[0].size() ? 0 : n+1);
    for(int i = 0; i < n+2; i++){
        cout << i << ": ";
        for(auto u : adj[i]) cout << u << ' ';
        cout << '\n';
    }
    bfs(root);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


