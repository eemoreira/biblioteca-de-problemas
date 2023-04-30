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
    vi a(n),b(n), ma(n), comp(n);
    for(auto&u:a) cin >> u;
    for(auto&u:b) cin >> u;
    pair<vi,vi> ans;
    int c = 0;
    for(int i = 0 ; i < n; i++){
        if(b[c] >= a[i]) ans.fst.eb(b[c]-a[i]);
        else c++,i--;
    }
    int ptr = 0;
    int keep = ptr;
    for(int i = 1; i < n; i++){
        if(a[i] <= b[ptr]) ptr = i;
        else{
            if(ptr == i-1) ptr++;
            /* cout << a[keep] << ' ' << a[i-1] << ' ' << b[ptr] << endl; */
            for(int k = keep; k < i; k++){
                ans.snd.eb(abs(a[k] - b[ptr-1]));
                keep = i;
                ptr = i;
            }
        }
    }
    if(ptr == n-1){
        for(int i = keep; i < n; i++){
            ans.snd.eb(abs(b[n-1] - a[i]));
        }
    }
    for(auto u : ans.fst) cout << u << ' ';
    cout << endl;
    for(auto u : ans.snd) cout << u << ' ';
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


