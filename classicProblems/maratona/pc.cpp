#include <bits/stdc++.h>

using namespace std;

void solve(){
    string h,v;
    getline(cin >> ws, h);
    getline(cin >> ws, v);
    int indexh=-1,indexv=-1;
    for(int i =0;i<h.size();i++){
        for(int k = 0; k<v.size(); k++){
            if(h[i] == v[k]){
                indexh = i + 1;
                indexv = k + 1;
            }
        }
    }
    cout << indexh << " " << indexv << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}