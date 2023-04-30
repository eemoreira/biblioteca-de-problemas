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
int vis[105];

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n; i++) vis[i] = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A') continue;
        int ok = 0;
        for(int k = i+1; k < n; k++){
            if(vis[k])continue;
            if(s[k] == 'A'){
                ok = 1;
                vis[k] = 1;
                break;
            }
        }
        if(!ok){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



