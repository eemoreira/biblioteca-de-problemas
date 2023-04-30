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
#define pf push_front
#define eb emplace_back

int ok2321 = 1;

void solve(){
    int n; cin >> n;
    vi a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n&1){
        cout << -1 << endl;
        return;
    }
    vector<ii> ans;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i+1]){
            ans.eb(i,i+1);
            i++;
        }
        else{
            ans.eb(i,i);
            ans.eb(i+1,i+1);
            i++;
        }
    }
    cout << (int)ans.size() << endl;
    for(auto u : ans) cout << u.fst << ' ' << u.snd << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



