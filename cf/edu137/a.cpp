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
    map<int,int> nh;
    for(int i = 0; i < n; i++){
        int a ; cin >> a;
        nh[a] = 1;
    }
    ll ans = 0;
    for(int i = 0; i < 10; i++){
        if(nh[i])continue;
        for(int k = i+1; k < 10; k++){
            if(nh[k])continue;
            ans++;
        }
    }
    cout << 6 * ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



