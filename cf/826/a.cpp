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
    string a,b; cin >> a >> b;
    map<char, int> tema,temb;
    for(auto u : a) tema[u]++;
    for(auto u : b) temb[u]++;
    if(tema['M'] || temb['M']){
        if(a == "M" && b == "M"){
            cout << '=' << endl;
        }
        else if(a == "M"){
            if(temb['L']) cout << '<' << endl;
            else if(temb['S']) cout << '>' << endl;
        }
        else if(b == "M"){
            if(tema['L']) cout << '>' << endl;
            else if(tema['S']) cout << '<' << endl;
        }
    }
    else{
        if(tema['L'] && temb['L']){
            if(tema['X'] > temb['X']) cout << '>' << endl;
            else if(tema['X'] < temb['X']) cout << '<' << endl;
            else cout << '=' << endl;
        }
        else if(tema['S'] && temb['S']){
            if(tema['X'] > temb['X']) cout << '<' << endl;
            else if(tema['X'] < temb['X']) cout << '>' << endl;
            else cout << '=' << endl;
        }
        else if(tema['S']) cout << '<' << endl;
        else if(tema['L']) cout << '>' << endl;
        else if(temb['S']) cout << '<' << endl;
        else if(temb['L']) cout << '>' << endl;
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



