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

int ok2321 = 1;

void solve(){
    int n; cin >> n;
    vector<char> s(n+1);
    for(int i = 1; i <= n; i++) cin >> s[i];
    ll cost = 0;
    vi vis(1+n);
    vis.assign(n+1,0);
    for(int i= 1; i <= n; i++){
        if(s[i]=='1') continue;
        int us = i;
        for(int k = us; k <= n; k+=us){
            if(s[k]=='1')break;
            if(!vis[k]){
                cost+=(ll)us;
                vis[k] = 1;
            }
            /* cout << k << ' '; */
        }
        /* cout << cost << endl; */
    }
    cout << cost << endl;
    
    
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



