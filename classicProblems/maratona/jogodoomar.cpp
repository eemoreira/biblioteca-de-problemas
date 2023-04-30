#include <iostream>
#include <string>
#include <vector>

using namespace std;
void solve();

int main(){
    solve();
    return 0;
}

void solve(){
    int n, count=0;
    cin >> n;
    vector <string> cartas;
    int arr2[n];

    const char arr[14] = {'A', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

    for(int i=0; i< n; i++){
        string temp;
        cin >> temp;
        cartas.push_back(temp);  
    }


    if(n > 9){

    for(int i=0; i<n;i++) arr[i] == 0;

    for(int i=0;i < 14; i++){ 
        int soma =0;
        for(int k=0; k<(n-9);k++){  
            for(int j=k; j<(9+k) ;j++){
                if(cartas[j][0] == arr[i]){
                    soma++;
                    if(soma == 3){
                        arr2[count] = j + 1;
                        count++;
                        soma =0;
                        break;
        }
            }
            
        }
        
        }
    }
    for(int i=0;i < count; i++){
        for(int k=i+1; k< count; k++){
            if(arr2[i] > arr2[k]){
            int store = arr2[i];
            arr2[i] = arr2[k];
            arr2[k] = store;
        }
        }
    }
    cout << arr2[0] << endl;
    }
    else{
    for(int i=0;i < 14; i++){ 
        int soma =0;
            for(int j=0; j<n ;j++){
                if(cartas[j][0] == arr[i]){
                    soma++;
                    if(soma == 3){
                        cout << j + 1 << endl;
                        count = 1;
                        soma =0;
                        break;
        }
            }
        }
    }
    }
    if(count == 0){
        cout << -1 << endl;
    }
}
    

