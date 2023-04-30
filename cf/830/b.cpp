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
    string s; cin >> s;
    s.pb('1');
    int f = 0;
    string t = s;
    sor(t);
    if(t == s){
        cout << 0 << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            f = i;
            break;
        }
    }
    int op = 1;
    int ans = 0;
    for(int i = f; i < n; i++){
        if(s[i] == '0' && op == 1){
            ans++;
            op = !op;
        }
        else if(s[i] == '1' && op == 0){
            ans++;
            op = !op;
        }
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



