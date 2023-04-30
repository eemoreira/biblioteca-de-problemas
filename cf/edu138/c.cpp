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
    vi a(n);
    for(auto &u : a) cin >> u;
    sor(a);
    int ans = 0;
    for(int k = 1; k <= n; k++){
        deque<int> dq;
        for(auto u : a){
            if(u > k)break;
            /* cout << u << ' '; */
            dq.pb(u);
        }
        /* cout << endl; */
        int cnt = 0;
        while((int)dq.size() >= 2){
            if(dq.back() > (k-cnt)){
                dq.pop_back();
                continue;
            }
            /* cout << "back: " << dq.back() << ' ' << cnt << ' ' << (int)dq.size() << endl; */
            dq.pop_back();
            dq.pop_front();
            cnt++;
        }
        if((int)dq.size() == 1){
            if(dq.front() <= (k - cnt)){
                cnt++;
            }
        }
        if(cnt >= k) ans = k;
        else{
            cout << ans << endl;
            return;
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



