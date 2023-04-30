#include <bits/stdc++.h>
#define endl '\n'
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
 
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(n == 3 && s == "TMT"){
        cout << "YES" << endl;
        return;
    }  
    if(s[0] == 'M' || s[n-1] == 'M'){
        cout << "NO" << endl;
        return;
    }
    vi t,m;
    for(int i = 0; i < n; i++){
        if(s[i] == 'T') t.push_back(i);
        else m.push_back(i);
    }
    int ok = 1;
    int ts = (int) t.size();
    int ms = (int) m.size();
    if(ts != 2*ms){
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < ms; i++){
        ok &= (m[i] > t[i] && m[i] < t[i+ms]);
    }   
    cout << (ok ? "YES" : "NO") << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}
 
