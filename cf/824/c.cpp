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
const int mx = 2e5 + 5;
int parent[27], child[27];

void solve(){

    int n; cin >> n;
    string t ; cin >> t;
    for(int i = 0; i < 26; i++) parent[i] = child[i] = -1;
    for(auto &u : t){
        int cur = u - 'a';
        if(child[cur] == -1){
            for(int k = 0; k < 26 ; k++){
                if(cur == k || parent[k] != -1) continue;
                int usin = k;
                int cnt =0;
                while(child[usin] != -1) usin = child[usin], cnt++;
                if(usin == cur && cnt < 25) continue;
                child[cur] = k;
                parent[k] = cur;
                break;
            }
        }
        u = child[cur] + 'a';
    }
    cout << t << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}




