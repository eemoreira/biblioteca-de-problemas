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

int ok2321 = 0;


void solve(){
    int n,d; cin >> n >> d;
    map<string,int> have;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int ind = 0;
        for(int k = 0; k < d; k++){
            if(s[k] == '*') ind = k;
        }
        for(char c = 'a'; c <= 'z'; c++){
            string t = s;
            t[ind] = c;
            have[t]++;
        }
    }
    int ma = 0;
    for(auto u : have) ma = max(ma,u.snd);
    vector<string> ans;
    for(auto u : have){
        if(u.snd == ma) ans.pb(u.fst);
    }
    sor(ans);
    cout << ans[0] << ' ' << ma << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



