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
    string s; cin >> s;
    int n = s.size();
    int open = n/2;
    if(n&1){
        cout << "NO" << endl;
        return;
    }
    for(auto u : s){
        open -= (u == '(');
    }
    /* cout << open << endl; */
    if(!open){
        cout << "YES" << endl;
        return;
    }
    string ans = "";
    int last = 0, f = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            if(open){
                ans += '(';
                open--;
                last = i;
            }
            else{
                if(!f) f = i;
                ans += ')';
            }
        }
        else ans += s[i];
    }
    /* cout << last << ' ' << f << endl; */
    swap(ans[last], ans[f]);
    int check = 0;
    bool ok = false;
    for(int i = 0 ; i < n; i++){
        check += (ans[i] == '(');
        check -= (ans[i] == ')');
        if(check < 0) ok = true;
    }
    if(!f) ok = 1;
    cout << (ok ? "YES" : "NO") << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



