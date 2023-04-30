#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
int arr[MAX+5];
char moves[MAX+5][MAX];

void solve(){
    int n; cin >> n;
    
    for(int i= 0; i< n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        for(int k =0; k< m;k++){
            char c; cin >> c;
            if(arr[i] == 9 && c == 'D') arr[i] = 0;
            else if(arr[i] == 0 && c == 'U') arr[i] = 9;
            else{
                if(c == 'U') arr[i]--;
                if(c == 'D') arr[i]++;
            }
        }
    }
    for(int i = 0; i<  n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
    solve();
    }
    return 0;
}
