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
    for(auto &u: a) cin >> u;
    vector<vi> where(n+1);
    vi freq(n+1);
    for(int i = 0; i < n ; i++){
        where[a[i]].pb(i);
        freq[a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(!freq[i]) cout << 0 << ' ';
        else{
            int todif = 0;
            for(int k = 0; k < (int) where[i].size()-1; k++){
                /* cout << where[i][k+1] << ' ' << where[i][k] << endl; */
                if(!((where[i][k+1] - where[i][k])&1)) todif++;
            }
            cout << freq[i] - todif << ' ';
        }
    }
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



