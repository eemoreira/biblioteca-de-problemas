#include <iostream>
#include <string>


using namespace std;

int main(){

    int qntd, tamanhomuralhas, pequeno, medio, grande;

    cin >> qntd >> tamanhomuralhas;

    int arrTitans[qntd],arrTamanhomuralhas[qntd];

    for(int i =0;i<qntd;i++){
        arrTamanhomuralhas[i] = tamanhomuralhas;
    }

    string tamanhos;
    getline(cin >> ws, tamanhos);

    int arr[3];
    for(int i=0; i<3;i++){
        cin >> arr[i];
    }

    for(int i=0; i< 3; i++){
        for(int j = i + 1; j < 3; j++){
            if (arr[i] > arr[j]){
                int guardar = arr[i];
                arr[i] = arr[j];
                arr[j] = guardar;
            }
        }
    }

    for(int i=0;i<qntd;i++){
        if (tamanhos[i] == 'P'){
            arrTitans[i] = arr[0];
        }
        if (tamanhos[i] == 'M'){
            arrTitans[i] = arr[1];
        }
        if (tamanhos[i] == 'G'){
            arrTitans[i] = arr[2];
        }
    } 

    int qtdmuralhas = 0;
    for(int i=0;i<qntd;i++){
        for(int j=0;j<qntd;j++){
            if(arrTitans[i] <= arrTamanhomuralhas[j]){
                arrTamanhomuralhas[j] -= arrTitans[i];
                break;
                }
            }
        
    }

    for(int i=0; i<qntd;i++){
        if(arrTamanhomuralhas[i] != tamanhomuralhas){
            qtdmuralhas++;
        }
    }

    cout << qtdmuralhas << endl;
}

