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
    int q; cin >> q;
    map<char,int> s,t;
    ll ssz=0, tsz=0;
    char mins = 'a', mat = 'a';
    for(int i = 0; i < q; i++){
        int a,d; cin >> a >> d;
        string temp; cin >> temp;
        if(a==1) for(auto u : temp) s[u] += d, ssz+=d, mins = min(u,mins);
        else for(auto u : temp) t[u] += d, tsz+=d, mat = max(mat,u);
        if(ssz >= tsz){
            cout << (mat > mins ? "YES" : "NO") << endl;
        } 
        else{
            if(mat == mins){
                int ok = 0;
                int f = 1;
                int db = 1;
                for(char c = mins ; c <= 'z'; c++){
                    if(s[c] == t[c]) continue;
                    if(s[c] > t[c]){
                        cout << "YES" << endl;
                        ok = 1;
                        f = 0;
                        db = 0;
                        break;
                    }
                    else{
                        f = 0;
                        for(char d = c+1; d <= 'z'; d++) db &= (!s[d]);
                        break;
                    }
                }
                if(f) cout << "YES" << endl;
                else if(!ok && db) cout << "YES" << endl;
                else if(!ok) cout << "NO" << endl;
            }
            else cout << (mins < mat ? "YES" : "NO") << endl;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



