#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<char, vector<char>, greater<char>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back
typedef pair<char,int> ic;

int ok2321 = 1;

void solve(){
    string s; cin >> s;
    string t = s;
    sor(t);
    if(s == t){
        cout << s << endl;
        return;
    }
    int n = (int)s.size();
    vi a(n);
    for(int i = 0; i < n; i++) a[i] = s[i]-'0';
    int qnts=0;
    vi done(n),qtd(10);
    done.assign(n,0);
    qtd.assign(10,0);
    for(int i = 0; i < 10; i++){
        if(qnts==n) break;
        int last = -1;
        for(int k = 0; k < n; k++){
            if(done[k])continue;
            if(i==a[k]) last = k;
        }
        if(last==-1)continue;
        for(int k = 0; k <= last; k++){
            if(done[k])continue;
            if(a[k]==a[last]){
                done[k] = 1;
                qtd[a[k]]++;
                qnts++;
            }
            else{
                done[k] = 1;
                qtd[min(a[k]+1,9)]++;
                qnts++;
            }
        }
    }
    for(int i = 0 ; i < 10; i++){
        /* cout << i << ' ' << qtd[i] << endl; */
        for(int k = 0; k < qtd[i]; k++){
            cout << i;
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



