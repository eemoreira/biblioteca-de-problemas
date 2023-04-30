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
    vi a(n);
    for(auto &u : a) cin >> u;
    map<int,int> freq;
    int ma = -1e9 - 5;
    for(auto u : a){
        freq[u]++;
        ma = max(ma,u);
    }
    int tot = ma;
    int ind = log2(tot);
    cout << ma << ' ';
    freq[ma]--;
    for(int k = ind-1; k >= 0; k--){
        /* cout << k << endl; */
        /* for(auto u : bt[k]) cout << "numero: " << u << " freq[]: " << freq[u] << endl; */
        /* cout << endl; */
        if((tot&(1<<k))) continue;
        int mk = -1e9 - 5;
        int ans = 0;
        for(auto u : a) if(freq[u]){
            if((u | tot) > mk){
                ans = u;
                mk = (u | tot);
            }
        }
        if(ans){
            cout << ans << ' ';
            tot |= ans;
            freq[ans]--;
        }
        if(tot == (1 << (ind+1)) - 1) break;
    }
    for(int i = 0; i < n; i++) if(freq[a[i]]){
        cout << a[i] << ' ';
        freq[a[i]]--;
    }
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



