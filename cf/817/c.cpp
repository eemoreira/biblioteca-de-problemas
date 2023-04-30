#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<vector<string>> a(3);
    map<string,int> tem;
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < n; k++){
            string s; cin >> s;
            a[i].push_back(s);
            tem[a[i][k]]++;
        }
    }
    vector<int> res(3);
    for(int i = 0; i < 3; i++){
       for(int k = 0; k < n; k++){
            if(tem[a[i][k]]){
                if(tem[a[i][k]] == 1) res[i]+=3;
                if(tem[a[i][k]] == 2) res[i]++;
            }
       }
    }
    for(int i = 0; i < 3; i++) cout << res[i] << ' ';
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

