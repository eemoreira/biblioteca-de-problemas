#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back

int ok2321 = 0;
const int mx = 2e5 + 5;
bool vis[mx];
int n,x,y;
stack<int> st;
vector<vi>  adj(mx);

void dfs(int v){
    vis[v] = true;
    /* cout << v << ' '; */
    /* cout << st.top() << endl; */
    for(auto u : adj[v]){
        if(!vis[u]){
            st.push(u);
            dfs(u);
        }
    }
    if(st.top() == y){
        return;
    }
    else if(!st.empty()) st.pop();
}

void solve(){
    cin >> n >> x >> y;
    for(int i = 0; i < n-1; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    st.push(x);
    dfs(x);
    vi ans;
    while(!st.empty()){
        ans.pb(st.top());
        st.pop();
    }
    for(int i = ans.size()-1; i>=0; i--) cout << ans[i] << ' ';
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



