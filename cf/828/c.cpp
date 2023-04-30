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
    int n;
    char c;
    cin >> n >> c;
    string s; cin >> s;
    vi g;
    int f = 0;
    for(int i = 0; i < n; i++){
        if(s[i]=='g'){
            f = i;
            break;
        }
    }
    int ans = 0;
    if(c == 'g'){
        cout << 0 << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        /* if(s[i] == c && i == n-1){ */
        /*     ans = max(ans, f + 1); */
        /* } */
        if(s[i] == c){
            int cnt = 0;
            while(s[i] != 'g' && i < n){
                i++;
                cnt++;
            }
            if(i == n){
                ans = max(cnt + f ,ans);
                break;
            }
            else ans = max(cnt, ans); 
            i--;
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



