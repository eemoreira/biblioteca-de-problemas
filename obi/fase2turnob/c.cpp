#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

const int mx = 1e6 + 5;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    map<char,int> ja;
    int pf[mx];
    pf[0] = 1;
    ja[s[0]] = 1;
    for(int i = 1; i < n; i++){
        if(!ja[s[i]]) {
            pf[i] = pf[i-1] + 1;
        }
        else pf[i] = pf[i-1];
        ja[s[i]] = 1;
    }
    for(int i = 1; i < n; i++){
        if(pf[s.substr(0,i-1).size()] == pf[n-i]){
            cout << (s.substr(0,i-1).size() < s.substr(i,n-i+1).size() ? s.substr(0,i) : s.substr(i,n-i+1)) << endl;
            return;
        }
    }
    cout << '*' << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

