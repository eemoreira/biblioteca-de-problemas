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
#define eb emplace_back

int ok2321 = 1;
const int mx = 110;
ll dp[mx][mx];

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(auto&u:a)cin>>u;
    // case 1 -> 1 even
    // case 2 -> 1 even or 2 even
    // case 3 -> 3 odd or 3 even
    // case 4 -> 3 odd 1 even or 4 even or 4 odd
    // case 5 -> 4 odd 1 even or 5 even or 3 odd 2 even
    // case n -> take even number of odd and its fine
    int odd = 0;
    for(auto &u : a) u = abs(u);
    for(auto u : a) odd += (u%2);
    int even = n - odd;
    if(odd%4 == 0 || odd%4 == 3){
        cout << "Alice\n";
    }
    else if(odd % 4 == 1){
        if(even % 4 == 1 || even % 4 == 3) cout << "Alice\n";
        else cout << "Bob\n";
    }
    else if(odd % 4 == 2){
        cout << "Bob\n";
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



