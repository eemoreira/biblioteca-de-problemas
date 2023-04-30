    #include <bits/stdc++.h>

    using namespace std;

    void solve(){
        int arr[3];
        int a,b,c;
        for(int i =0;i<3;i++){
            cin >> arr[i];
        }
        a = arr[0];
        b = arr[1];
        c = arr[2];
        sort(begin(arr),end(arr));
        for(int i = 0; i<3; i++){
            if(a == arr[i]) cout << 1 << endl;
            if(b == arr[i]) cout << 2 << endl;
            if(c == arr[i]) cout << 3 << endl;
        }
    }

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        solve();
        return 0;
    }