#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
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
    int n; cin >> n;
    int cnt = 0;
    string a;
    for(int i = 0; i < n; i++) a += "BAN";
    vector<ii> ans;
    vi vis(a.size());
    for(int i = 0; i < a.size() ; i++){
        if(a[i] == 'B' && !vis[i]){
            if(a.size() - 3*cnt - 1 <= i)continue;
            ans.eb(i+1,a.size()-3*cnt);
            vis[a.size()-3*cnt-1] = 1;
            swap(a[i],a[a.size() - 3*cnt]);
            cnt++;
        }
    }
    cout << cnt << '\n';
    for(auto u : ans) cout << u.fst << ' ' << u.snd << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



