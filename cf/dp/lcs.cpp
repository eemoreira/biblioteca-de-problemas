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

const int mx = 3e3 + 5;
int lcs[mx][mx];
int vis[mx];

void solve(){
    string s,t; cin >> s >> t;
    for(int i = 1; i <= (int)s.size(); i++){
        for(int k = 1; k <= (int)t.size() ;k++){
            lcs[i][k] = max(lcs[i-1][k], lcs[i][k-1]); 
            if(s[i-1]==t[k-1]){
                lcs[i][k] = 1 + lcs[i-1][k-1];
            }
        }
    }
    int c = s.size(), d = t.size();
    vector<char> ans(lcs[s.size()][t.size()]); 
    ans.assign(lcs[s.size()][t.size()],'0');
    int ind = lcs[s.size()][t.size()];
    while(c > 0 && d > 0){
        if(s[c-1] == t[d-1]){
            ans[ind-1] = s[c-1];
            ind--;c--;d--;
        }
        else{
            if(lcs[c-1][d] > lcs[c][d-1]) c--;
            else d--;
        }
    }
    for(auto u : ans) if(u != '0') cout << u;
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



