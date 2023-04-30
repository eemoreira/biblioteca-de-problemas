    #include <bits/stdc++.h> 

    void solve();

    using namespace std;


    int main(){
        ios_base::sync_with_stdio(0); 
        cin.tie(0); 
        solve();
        return 0;
    }

    void solve(){

        int qntd, count=0;

        cin >> qntd;

        vector<string> batalha(qntd);
        for(int i=0;i<qntd;i++){
            string temp;
            cin >> temp;
            batalha[i] = temp;
        }

        for(int i=0;i<qntd;i++){
            for(int j=0;j<(batalha[i]).size(); j++){
                if(batalha[i][j] == 'C' && batalha[i][j+1] == 'D') count++;
            }
        }
        cout << qntd - count << endl;

    }