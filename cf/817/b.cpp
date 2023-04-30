#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    string top, bottom; cin >> top >> bottom;
    int ok = 1;
    for(int i = 0; i < n; i++){
        if(top[i] != bottom[i]){
            if(top[i] == 'B' && bottom[i] == 'G') continue;
            if(top[i] == 'G' && bottom[i] == 'B') continue;
            else{
                ok = 0;
                break;
            }
        }
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

