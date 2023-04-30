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

int ok2321 = 0;

void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto &u : a){
        cin >> u;
    }
    int ans = 1;
    for(int i = 0; i < n; i++){
        for(int k = i+1; k < n; k++){
            if(a[k] == a[i])continue;
            int anss = 2;
            int op = 0;
            for(int d = k+1; d < n; d++){
                if(a[d] == a[i] && !op){ 
                    op = !op;
                    anss++;
                }
                else if(a[d] == a[k] && op){
                    op = !op;
                    anss++;
                }
            }
            ans = max(ans,anss);
        }
    }
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



