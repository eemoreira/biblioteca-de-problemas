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
    int n; cin >> n;
    string s; cin >> s;
    int f = 0;
    int ok = 0;
    int c = 0;
    for(int i = 0 ; i < n ; i++){
        ok |= (s[i] == '1');
        c += (!ok);
    }
    string us = "";
    for(int i = c; i < n; i++){
        us += s[i];
    }
    s = us;
    n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i]=='0'){
            f = i;
            break;
        }
    }
    string ans = "0";
    string rest = s.substr(f,n-f);
    for(int i = 0; i < f; i++){
        string res = s;
        string cur = s.substr(i,n-f);
        for(int k = 0; k < n-f; k++){
            res[f+k] = (cur[k] == '1' || rest[k] == '1' ? '1' : '0');
        }
        ans = max(ans,res);
    }
    cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



