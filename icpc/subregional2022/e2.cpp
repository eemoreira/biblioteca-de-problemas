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
const int mx = 1e6 + 5;
int freq[mx];
int h[mx];

void solve(){
    int n; cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> h[i];
        if(freq[h[i]+1]) freq[h[i]+1]--;
        else ans++;
        freq[h[i]]++;
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



